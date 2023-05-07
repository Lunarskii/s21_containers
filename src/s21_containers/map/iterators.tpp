#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_ITERATORS_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_ITERATORS_TPP_

namespace s21 {

template<typename Key, typename T>
map<Key, T>::MapIterator::MapIterator(typename BinaryTree<value_type>::iterator it) : it_(it) {}



}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_ITERATORS_TPP_
