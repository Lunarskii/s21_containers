#ifndef SRC_S21_CONTAINERS_H_LIST_LIST_H_
#define SRC_S21_CONTAINERS_H_LIST_LIST_H_
#pragma once

#include <cstddef>
#include <initializer_list>

template <typename T>
class List {
    public:
        class Node;
        class ListIterator;
        // class ListConstIterator;
    
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using iterator = List<T>::ListIterator;
        // using const_iterator = List<const T>::ListConstIterator;
        using size_type = std::size_t;


        /*                  CONSTRUCTORS/DESTRUCTORS                                            */
        List();                                              // default constructor, creates an empty list
        List(size_type n);                                   // parameterized constructor, creates the list of size n
        List(std::initializer_list<value_type> const &items);// initializer list constructor, creates a list initizialized using std::initializer_list
        List(const List &other);                             // copy constructor 
        List(List &&other);                                  // move constructor      
        ~List();                                             // destructor

        // void erase(int index);
        // typename S21List<T>::Node* insert(int index, double data);



        iterator begin();                                       // returns an iterator to the beginning
        iterator end();                                         // returns an iterator to the end
        const_reference front();                                // access the first element
        const_reference back();                                 // access the last element
        void clear();                                           // clears the contents
        bool empty();                                           // checks whether the container is empty
        void push_back(const_reference value);                  // adds an element to the end
        void pop_back();                                        // removes the last element
        void push_front(const_reference value);                 // adds an element to the head
        void pop_front();                                       // removes the first element

    private:
        Node *head;
        Node *tail;
};

template <typename value_type>
class List<value_type>::Node {
    public:
        Node(const value_type& d = value_type{}, Node* p = nullptr, Node* n = nullptr);
        value_type data;
        Node *prev;
        Node *next;

    private:
};

template <typename value_type>
class List<value_type>::ListIterator {
    public:
        // Конструктор по умолчанию
        ListIterator() = default;

        // Конструктор с указанием начального узла
        ListIterator(Node *node);

        // Операторы инкремента и декремента
        ListIterator& operator++();
        ListIterator& operator--();
        ListIterator operator++(int);
        ListIterator operator--(int);

        // Операторы сравнения
        bool operator==(const ListIterator& other) const;
        bool operator!=(const ListIterator& other) const;

        // Операторы доступа к элементам
        reference operator*() const;
        pointer operator->() const;
            
    private:
        Node* node_{nullptr};
};

// template <typename value_type>
// class List<value_type>::ListConstIterator {
//     public:
//     private:
// };

#include "list.tpp"
#include "iterators.tpp"

#endif  // SRC_S21_CONTAINERS_H_LIST_LIST_H_
