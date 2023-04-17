#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_TPP_

namespace s21 {
template<typename value_type>
List<value_type>::Node::Node(const value_type& d, Node* p, Node* n) : data(d), prev(p), next(n) {}

template<typename value_type>
List<value_type>::List() : head(nullptr), tail(nullptr) {}

template<typename value_type>
List<value_type>::List(size_type n) {
    for (; n > 0; --n) {
        push_back(value_type{});
    }
}

template<typename value_type>
List<value_type>::List(std::initializer_list<value_type> const &items) {
    for (auto& i : items) {
        push_back(i);
    }
}

template<typename value_type>
List<value_type>::List(const List &other) {
    for (const_iterator it = other.cbegin(); it != other.cend(); ++it) {
        push_back(*it);
    }
}

template<typename value_type>
List<value_type>::List(List &&other) {
    swap(other);
}

template<typename value_type>
List<value_type>::~List() {
    while (head != nullptr) pop_front();
}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::size() {
    size_type n = 0;

    for (iterator it = begin(); it != end(); ++it) { ++n; }

    return n;
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::insert(iterator pos, const_reference value) {
    if (empty() || pos.node_ == nullptr) { // список пуст или итератор находится за последним элементом
        push_back(value);
        return iterator(tail);
    } else if (pos.node_->prev == nullptr) { // итератор находится на первом элементе
        push_front(value);
        return iterator(head);
    } else { // все остальные случаи, когда итератор находится не в начале и не в конце списка
        Node *nextNode = pos.node_;
        Node *prevNode = pos.node_->prev;
        Node *newNode = new Node(value, prevNode, nextNode);

        prevNode->next = newNode;
        nextNode->prev = newNode;

        return iterator(newNode);
    }
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::begin() {
    if (empty()) {
        return iterator(head);
    } else {
        return iterator(head, head, tail);
    }
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::end() {
    if (empty()) {
        return iterator(tail);
    } else {
        return iterator(tail->next, head, tail);
    }
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::cbegin() const {
    if (head != nullptr) {
        return const_iterator(head, head, tail);
    } else {
        return const_iterator(nullptr);
    }
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::cend() const {
    if (tail != nullptr) {
        return const_iterator(tail->next, head, tail);
    } else {
        return const_iterator(nullptr);
    }
}

template<typename value_type>
typename List<value_type>::const_reference List<value_type>::front() {
    if (empty()) {
        static const const_reference default_value{};
        return default_value;
    } else {
        return *begin();
    }
}

template<typename value_type>
typename List<value_type>::const_reference List<value_type>::back() {
    if (empty()) {
        static const const_reference default_value{};
        return default_value;
    } else  {
        return *(--end());
    }
}

template<typename value_type>
bool List<value_type>::empty() {
    return head == nullptr && tail == nullptr;
}

template<typename value_type>
void List<value_type>::splice(const_iterator pos, List& other) {
    for (List<value_type>::iterator it = other.begin(); it != other.end(); ++it) {
        insert(pos, *it);
    }
    other.clear();
}

template<typename value_type>
void List<value_type>::unique() {
    for (List<value_type>::iterator it = ++begin(); it != end(); ++it) {
        if (*it == *(it - 1)) {
            erase(it - 1);
        }
    }
}

template<typename value_type>
void List<value_type>::merge(List& other) {
    List<value_type> tempList(*this);
    iterator it_L1 = tempList.begin();
    iterator it_L2 = other.begin();

    clear();
    while (it_L1 != tempList.end() && it_L2 != other.end()) {
        if (*it_L1 < *it_L2) {
            push_back(*it_L1);
            tempList.erase(it_L1++);
        } else {
            push_back(*it_L2);
            other.erase(it_L2++);
        }
    }
    splice(end(), tempList);
    splice(end(), other);
}

template<typename value_type>
void List<value_type>::sort() {
    for (iterator it_i = ++begin(); it_i != end(); ++it_i) {
        value_type key = *it_i;
        iterator it_j = it_i - 1;

        for (; it_j.node_ != nullptr && *it_j > key; --it_j) {
            *(it_j + 1) = *it_j;
        }
        *(it_j + 1) = key;
    }
}

template<typename value_type>
void List<value_type>::erase(iterator pos) {
    if (pos.node_ == nullptr) {
        std::cerr << "Invalid pointer" << std::endl;
        std::abort();
    } else {
        if (pos.node_->prev == nullptr) { // если первый элемент
            pop_front();
        } else if (pos.node_->next == nullptr) { // если последний элемент
            pop_back();
        } else { // если элемент не в конце и не в начале
            Node *temp = pos.node_;
            Node *prevNode = pos.node_->prev;
            Node *nextNode = pos.node_->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete temp;
        }
    }
}

template<typename value_type>
void List<value_type>::clear() {
    this->~List();
}

template<typename value_type>
void List<value_type>::reverse() {
    iterator it_left = begin();
    iterator it_right = --end();

    for (size_type i = 0; i < size() / 2; i++, ++it_left, --it_right) {
        std::swap(*it_left, *it_right);
    }
}

template<typename value_type>
void List<value_type>::swap(List& other) {
    if (this != &other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
    }
}

template<typename value_type>
template<typename... Args>
typename List<value_type>::iterator List<value_type>::emplace(const_iterator pos, Args&&... args) {
    auto args_list = std::initializer_list<value_type>{std::forward<Args>(args)...};

    for (auto& i : args_list) {
        insert(pos, i);
    }

    return pos;
}

template<typename value_type>
template<typename... Args>
void List<value_type>::emplace_back(Args&&... args) {
    emplace(end(), args...);
}

template<typename value_type>
template<typename... Args>
void List<value_type>::emplace_front(Args&&... args) {
    emplace(begin(), args...);
}

template<typename value_type>
void List<value_type>::push_front(const_reference data) {
    if (head == nullptr) {
        head = tail = new Node(data);
    } else {
        head->prev = new Node(data, nullptr, head);
        head = head->prev;
    }
}

template<typename value_type>
void List<value_type>::push_back(const_reference data) {
    if (tail == nullptr) {
        tail = head = new Node(data);
    } else {
        tail->next = new Node(data, tail);
        tail = tail->next;
    }
}

template<typename value_type>
void List<value_type>::pop_front() {
    if (head != nullptr) {
        Node *tempHead = head;

        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete tempHead;
    }
}

template<typename value_type>
void List<value_type>::pop_back() {
    if (tail != nullptr) {
        Node *temp = tail;

        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }
}

template<typename value_type>
List<value_type>& List<value_type>::operator=(const List& other) {
    if (this != &other) {
        clear();
        new (this) List(other);
    }
    
    return *this;
}

template<typename value_type>
List<value_type>& List<value_type>::operator=(List &&other) {
    if (this != &other) {
        clear();
        new (this) List(std::move(other));
    }

    return *this;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_TPP_
