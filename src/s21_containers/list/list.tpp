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

template<typename value_type>
typename List<value_type>::iterator List<value_type>::begin() {
    iterator it(head);

    return it;
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::begin() const {
    const_iterator it(head);

    return it;
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::end() {
    iterator it(tail->next);

    return it;
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::end() const {
    const_iterator it(tail->next);

    return it;
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
void List<value_type>::clear() {
    this->~List();
}

template<typename value_type>
bool List<value_type>::empty() {
    return head == nullptr && tail == nullptr;
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

#endif  // SRC_S21_CONTAINERS_H_LIST_LIST_TPP_
