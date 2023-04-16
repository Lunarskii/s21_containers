#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_MULTISET_MULTISET_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_MULTISET_MULTISET_H_

#include <initializer_list>
#include <limits>

#include "../../s21_containers/binaryTree/binary_tree.h"

namespace s21 {
template<typename T>
class multiset {
    public:
        class MultisetIterator;

        using key_type = T;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = multiset<T>::MultisetIterator;
        using const_iterator = multiset<T>::MultisetIterator;
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
        BinaryTree<value_type> tree;
};

template<typename value_type>
class multiset<value_type>::MultisetIterator {
    public:
        MultisetIterator() = default;
        MultisetIterator(typename BinaryTree<value_type>::iterator it);
        
        // Операторы инкремента и декремента
        MultisetIterator& operator++();
        MultisetIterator& operator--();
        MultisetIterator operator++(int);
        MultisetIterator operator--(int);

        // Операторы сравнения
        bool operator==(const MultisetIterator& other) const;
        bool operator!=(const MultisetIterator& other) const;

        // Операторы перемещения/сложения
        // MultisetIterator operator+(size_type n) const;
        // MultisetIterator operator-(size_type n) const;

        // Операторы доступа к элементам
        const_reference operator*() const;
    private:
        typename BinaryTree<value_type>::BinaryTreeIterator it_;
};

}  // namespace s21

#include "multiset.tpp"
#include "iterators.tpp"

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_MULTISET_MULTISET_H_
