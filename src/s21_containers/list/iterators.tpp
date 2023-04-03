#ifndef SRC_S21_CONTAINERS_H_LIST_ITERATORS_TPP_
#define SRC_S21_CONTAINERS_H_LIST_ITERATORS_TPP_

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
    return node_->data;
}

template<typename value_type>
typename List<value_type>::pointer List<value_type>::ListIterator::operator->() const {
    return &node_->data;
}

#endif  // SRC_S21_CONTAINERS_H_LIST_ITERATORS_TPP_