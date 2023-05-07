#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_MAP_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_MAP_TPP_

namespace s21 {
template<typename Key, typename T>
map<Key, T>::map() {}

template<typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const &items) {
	BinaryTree<value_type> temp(items);
	tree = temp; // можно ли сразу в tree?
}

template<typename Key, typename T>
map<Key, T>::map(const map &other) {
	tree = other.tree;
}

template<typename Key, typename T>
map<Key, T>::map(map &&other) {
	tree = std::move(other.tree);
}

template<typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
    return iterator(tree.begin());
}

template<typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
    return iterator(tree.end());
}

template<typename Key, typename T>
bool map<Key, T>::empty() {
    return tree.empty();
}

template<typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() {
    return tree.size();
}

template<typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() {
    return tree.max_size();
}

template<typename Key, typename T>
void map<Key, T>::clear() {
    tree.clear();
}

// template<typename Key, typename T>
// std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(const_reference value) {
//     return tree.insert(value);
// }


template<typename Key, typename T>
void map<Key, T>::erase(iterator pos) {
    tree.erase(*pos);
}

template<typename Key, typename T>
void map<Key, T>::swap(map& other) {
    std::swap(tree, other.tree);
}

template<typename Key, typename T>
void map<Key, T>::merge(map& other) {
    tree.merge(other.tree);
}

template<typename Key, typename T>
bool map<Key, T>::contains(const_reference key) {
    return tree.contains(key);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_MAP_TPP_
