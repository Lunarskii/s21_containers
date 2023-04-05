#ifndef SRC_S21_CONTAINERS_H_LIST_ITERATORS_TPP_
#define SRC_S21_CONTAINERS_H_LIST_ITERATORS_TPP_

// <ListIterator>
template<typename value_type>
List<value_type>::ListIterator::ListIterator(Node *node) : node_(node) {}

template<typename value_type>
typename List<value_type>::ListIterator& List<value_type>::ListIterator::operator++() {
    node_ = node_->next;
    return *this;
}

template<typename value_type>
typename List<value_type>::ListIterator& List<value_type>::ListIterator::operator--() {
    node_ = node_->prev;
    return *this;
}

template<typename value_type>
typename List<value_type>::ListIterator List<value_type>::ListIterator::operator++(int) {
    ListIterator it(*this);
    ++(*this);
    return it;
}

template<typename value_type>
typename List<value_type>::ListIterator List<value_type>::ListIterator::operator--(int) {
    ListIterator it(*this);
    --(*this);
    return it;
}

template<typename value_type>
bool List<value_type>::ListIterator::operator==(const ListIterator& other) const {
    return node_ == other.node_;
}

template<typename value_type>
bool List<value_type>::ListIterator::operator!=(const ListIterator& other) const {
    return !(*this == other);
}

template<typename value_type>
typename List<value_type>::reference List<value_type>::ListIterator::operator*() const {
    if (node_ == nullptr) {
        throw std::invalid_argument("Invalid index");
    }

    return node_->data;
}

template<typename value_type>
typename List<value_type>::pointer List<value_type>::ListIterator::operator->() const {
    return &node_->data;
}

// <ListConstIterator>
template<typename value_type>
List<value_type>::ListConstIterator::ListConstIterator(Node *node) : node_(node) {}

template<typename value_type>
typename List<value_type>::ListConstIterator& List<value_type>::ListConstIterator::operator++() {
    node_ = node_->next;
    return *this;
}

template<typename value_type>
typename List<value_type>::ListConstIterator& List<value_type>::ListConstIterator::operator--() {
    node_ = node_->prev;
    return *this;
}

template<typename value_type>
typename List<value_type>::ListConstIterator List<value_type>::ListConstIterator::operator++(int) {
    ListConstIterator it(*this);
    ++(*this);
    return it;
}

template<typename value_type>
typename List<value_type>::ListConstIterator List<value_type>::ListConstIterator::operator--(int) {
    ListConstIterator it(*this);
    --(*this);
    return it;
}

template<typename value_type>
bool List<value_type>::ListConstIterator::operator==(const ListConstIterator& other) const {
    return node_ == other.node_;
}

template<typename value_type>
bool List<value_type>::ListConstIterator::operator!=(const ListConstIterator& other) const {
    return !(*this == other);
}

template<typename value_type>
typename List<value_type>::const_reference List<value_type>::ListConstIterator::operator*() const {
    return node_->data;
}

template<typename value_type>
typename List<value_type>::const_pointer List<value_type>::ListConstIterator::operator->() const {
    return &node_->data;
}


#endif  // SRC_S21_CONTAINERS_H_LIST_ITERATORS_TPP_
