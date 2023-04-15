#ifndef SRC_S21_CONTAINERS_H_SET_SET_H_
#define SRC_S21_CONTAINERS_H_SET_SET_H_
// #pragma once

#include "../binaryTree/binary_tree.h"

namespace s21 {
template<typename T>
class set {
    public:
        class SetIterator;

        using key_type = T;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = set<T>::SetIterator;
        using const_iterator = set<T>::SetIterator;
        // using iterator = typename BinaryTree<T, Compare>::iterator;
        // using const_iterator = typename BinaryTree<T, Compare>::const_iterator;
        using size_type = std::size_t;
        // using iterator_category = std::bidirectional_iterator_tag;
        // using difference_type = std::ptrdiff_t;

        /*                  CONSTRUCTORS/DESTRUCTORS                                            */
        set();                                                      // default constructor, creates empty set
        set(std::initializer_list<value_type> const &items);        // initializer list constructor, creates the set initizialized using std::initializer_list
        set(const set &other);                                          // copy constructor
        set(set &&other);                                               // move constructor
        ~set() = default;                                                     // destructor

        /*                  METHODS                                                             */
        iterator begin();                                           // returns an iterator to the beginning
        iterator end();                                             // returns an iterator to the end

        bool empty();                                               // checks whether the container is empty
        size_type size();                                           // returns the number of elements
        size_type max_size();                                       // returns the maximum possible number of elements

        void clear();                                               // clears the contents
        std::pair<iterator, bool> insert(const_reference value);  // inserts node and returns iterator to where the element is in the container and bool denoting whether the insertion took place
        void erase(iterator pos);                                   // erases element at pos
        void swap(set& other);                                      // swaps the contents
        void merge(set& other);                                     // splices nodes from another container

        iterator find(const_reference key);                              // finds element with specific key
        bool contains(const_reference key);                              // checks if the container contains element with specific key

        template <typename... Args>
        std::pair<iterator, bool> emplace(Args&&... args);   // inserts new elements into the container

        /*                  OPERATORS                                                           */    
        set& operator=(set&& other);                                         // assignment operator overload for moving object
        set& operator=(set& other);

    private:
        BinaryTree<value_type> tree;
};

template<typename value_type>
class set<value_type>::SetIterator {
    public:
        SetIterator() = default;
        SetIterator(typename BinaryTree<value_type>::iterator it);
        
        // Операторы инкремента и декремента
        SetIterator& operator++();
        SetIterator& operator--();
        SetIterator operator++(int);
        SetIterator operator--(int);

        // Операторы сравнения
        bool operator==(const SetIterator& other) const;
        bool operator!=(const SetIterator& other) const;

        // Операторы перемещения/сложения
        SetIterator operator+(size_type n) const;
        SetIterator operator-(size_type n) const;

        // Операторы доступа к элементам
        const_reference operator*() const;
    private:
        typename BinaryTree<value_type>::BinaryTreeIterator it_;
};

}  // namespace s21

#include "set.tpp"
#include "iterators.tpp"

#endif  // SRC_S21_CONTAINERS_H_SET_SET_H_
