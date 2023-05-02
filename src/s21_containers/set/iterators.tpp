#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_SET_ITERATORS_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_SET_ITERATORS_TPP_

namespace s21 {

template<typename value_type>
set<value_type>::SetIterator::SetIterator(typename BinaryTree<value_type>::iterator it) : it_(it) {}

template<typename value_type>
typename set<value_type>::SetIterator& set<value_type>::SetIterator::operator++() {
    ++it_;
    return *this;
}

template<typename value_type>
typename set<value_type>::SetIterator& set<value_type>::SetIterator::operator--() {
    --it_;
    return *this;
}

template<typename value_type>
typename set<value_type>::SetIterator set<value_type>::SetIterator::operator++(int) {
    return it_++;
}

template<typename value_type>
typename set<value_type>::SetIterator set<value_type>::SetIterator::operator--(int) {
    return it_--;
}

template<typename value_type>
bool set<value_type>::SetIterator::operator==(const SetIterator& other) const { return it_ == other.it_; }

template<typename value_type>
bool set<value_type>::SetIterator::operator!=(const SetIterator& other) const { return !(*this == other); }

template<typename value_type>
typename set<value_type>::const_reference set<value_type>::SetIterator::operator*() const { return *it_; }

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_SET_ITERATORS_TPP_
