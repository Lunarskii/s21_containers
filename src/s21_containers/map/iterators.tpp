#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_ITERATORS_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_ITERATORS_TPP_

namespace s21 {

template<typename Key, typename T>
map<Key, T>::MapIterator::MapIterator(typename BinaryTree<value_type>::iterator it) : it_(it) {}

template<typename Key, typename T>
typename map<Key, T>::MapIterator& map<Key, T>::MapIterator::operator++() {
    ++it_;
    return *this;
}

template<typename Key, typename T>
typename map<Key, T>::MapIterator& map<Key, T>::MapIterator::operator--() {
    --it_;
    return *this;
}

template<typename Key, typename T>
typename map<Key, T>::MapIterator map<Key, T>::MapIterator::operator++(int) {
    return it_++;
}

template<typename Key, typename T>
typename map<Key, T>::MapIterator map<Key, T>::MapIterator::operator--(int) {
    return it_--;
}

template<typename Key, typename T>
bool map<Key, T>::MapIterator::operator==(const MapIterator& other) const { return it_ == other.it_; }

template<typename Key, typename T>
bool map<Key, T>::MapIterator::operator!=(const MapIterator& other) const { return !(*this == other); }

template<typename Key, typename T>
typename map<Key, T>::MapIterator::const_reference map<Key, T>::MapIterator::operator*() const { return *it_; }

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_ITERATORS_TPP_
