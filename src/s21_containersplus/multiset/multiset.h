#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_MULTISET_MULTISET_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_MULTISET_MULTISET_H_

#include <initializer_list>
#include <limits>

#include "../../s21_containers/binaryTree/binary_tree.h"

namespace s21 {
template<typename T>
class multiset {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = typename BinaryTree<T>::BinaryTreeConstIterator;
        using const_iterator = iterator;
        using size_type = std::size_t;

        /*                  CONSTRUCTORS/DESTRUCTORS                                            */
        multiset();
        multiset(std::initializer_list<value_type> const &items);
        multiset(const multiset& other);
        multiset(multiset&& other);
        ~multiset() = default;

        /*                  METHODS                                                             */
        iterator begin();
        iterator end();

        bool empty();
        size_type size();
        size_type max_size();

        void clear();
        iterator insert(const_reference value);
        void erase(iterator pos);
        void swap(multiset& other);
        void merge(multiset& other);

        size_type count(const_reference key);
        iterator find(const_reference key);
        bool contains(const_reference key);
        std::pair<iterator, iterator> equal_range(const_reference key);
        iterator lower_bound(const_reference key);
        iterator upper_bound(const_reference key);

        template <typename... Args>
        std::pair<iterator, bool> emplace(Args&&... args);

        /*                  OPERATORS                                                           */
        multiset& operator=(multiset&& other);
        multiset& operator=(const multiset& other);

    private:
        BinaryTree<value_type> tree = NUNIQUE;
};

}  // namespace s21

#include "multiset.tpp"

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_MULTISET_MULTISET_H_
