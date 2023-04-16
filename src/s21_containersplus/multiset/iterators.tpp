

namespace s21 {

template<typename value_type>
multiset<value_type>::MultisetIterator::MultisetIterator(typename BinaryTree<value_type>::iterator it) : it_(it) {}

template<typename value_type>
typename multiset<value_type>::MultisetIterator& multiset<value_type>::MultisetIterator::operator++() {
    ++it_;
    return *this;
}

template<typename value_type>
typename multiset<value_type>::MultisetIterator& multiset<value_type>::MultisetIterator::operator--() {
    --it_;
    return *this;
}

template<typename value_type>
typename multiset<value_type>::MultisetIterator multiset<value_type>::MultisetIterator::operator++(int) {
    return it_++;
}

template<typename value_type>
typename multiset<value_type>::MultisetIterator multiset<value_type>::MultisetIterator::operator--(int) {
    return it_--;
}

template<typename value_type>
bool multiset<value_type>::MultisetIterator::operator==(const MultisetIterator& other) const { return it_ == other.it_; }

template<typename value_type>
bool multiset<value_type>::MultisetIterator::operator!=(const MultisetIterator& other) const { return !(*this == other); }

template<typename value_type>
typename multiset<value_type>::const_reference multiset<value_type>::MultisetIterator::operator*() const { return *it_; }

}  // namespace s21