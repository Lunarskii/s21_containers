#ifndef SRC_S21_CONTAINERS_H_LIST_LIST_TPP_
#define SRC_S21_CONTAINERS_H_LIST_LIST_TPP_

template<typename value_type>
List<value_type>::Node::Node(const value_type& d, Node* p, Node* n) : data(d), prev(p), next(n) {}

template<typename value_type>
List<value_type>::List() : head(nullptr), tail(nullptr) {}

template<typename value_type>
List<value_type>::List(size_type n) {
    // создать функцию для выдачи исключений и проверки доступности памяти
    // if (n > max_size()) throw "";

    for (; n > 0; --n) {
        push_back(value_type{});
    }
}

template<typename value_type>
List<value_type>::List(std::initializer_list<value_type> const &items) {
    // исключение
    // if (items.size() > max_size()) throw ""

    for (auto& i : items) {
        push_back(i);
    }
}

template<typename value_type>
List<value_type>::List(const List &other) {
    for (const_iterator it = other.begin(); it != other.end(); ++it) {
        push_back(*it);
    }
}

template<typename value_type>
List<value_type>::List(List &&other) : List(other) {
    other.clear();
}

template<typename value_type>
List<value_type>::~List() {
    while (head != nullptr) pop_front();
}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::max_size() { // проверить правильно ли работает данный метод
    return std::numeric_limits<size_type>::max();
}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::size() {
    size_type n = 0;

    if (!empty()) {
        for (iterator it = begin(); it != end(); ++it) n++;
    }

    return n;
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::insert(iterator pos, const_reference value) {
    if (empty() || pos.node_ == nullptr) { // список пуст или итератор находится за последним элементом
        push_back(value);
        iterator it(tail);
        return it;
    } else if (pos.node_->prev == nullptr) { // итератор находится на первом элементе
        push_front(value);
        iterator it(head);
        return it;
    } else { // все остальные случаи, когда итератор находится не в начале и не в конце списка
        Node *nextNode = pos.node_;
        Node *prevNode = pos.node_->prev;
        Node *newNode = new Node(value, prevNode, nextNode);

        prevNode->next = newNode;
        nextNode->prev = newNode;

        iterator it(newNode);
        return it;
    }
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::begin() {
    if (head != nullptr) {
        iterator it(head, head);
        return it;
    } else {
        iterator it(nullptr);
        return it;
    }
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::begin() const {
    if (head != nullptr) {
        const_iterator it(head);
        return it;
    } else {
        const_iterator it(nullptr);
        return it;
    }
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::end() {
    if (tail != nullptr) {
        iterator it(tail->next);
        return it;
    } else {
        iterator it(nullptr);
        return it;
    }
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::end() const {
    if (tail != nullptr) {
        const_iterator it(tail->next);
        return it;
    } else {
        const_iterator it(nullptr);
        return it;
    }
}

template<typename value_type>
typename List<value_type>::const_reference List<value_type>::front() {
    return head->data;
}

template<typename value_type>
typename List<value_type>::const_reference List<value_type>::back() {
    return tail->data;
}

template<typename value_type>
bool List<value_type>::empty() {
    return head == nullptr && tail == nullptr;
}

template<typename value_type>
void List<value_type>::erase(iterator pos) {
    if (pos.node_ == nullptr) {
        std::cerr << "Invalid pointer" << std::endl;
        std::abort();
    } else {
        if (pos.node_->prev == nullptr) { // если первый элемент
            pop_front();
        } else if (pos.node->next == nullptr) { // если последний элемент
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
    iterator it_right(tail);

    for (int i = 0; i < size() / 2; i++, ++it_left, --it_right) {
        swap_elements(*it_left, *it_right);
    }
}

template<typename value_type>
void List<value_type>::swap(List& other) {
    Node *tempHead = head;
    Node *tempTail = tail;
    
    head = other.head;
    tail = other.tail;
    other.head = tempHead;
    other.tail = tempTail;
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
        tail = head = new Node(data, nullptr, nullptr);
    } else {
        tail->next = new Node(data, tail, nullptr);
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
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
    }
}

template<typename value_type>
List<value_type>& List<value_type>::operator=(List &&other) {
    this->clear();
    new (this) List(other);
}

template<typename value_type>
void List<value_type>::swap_elements(value_type &a, value_type &b) {
    value_type temp = a;
    a = b;
    b = temp;
}

#endif  // SRC_S21_CONTAINERS_H_LIST_LIST_TPP_
