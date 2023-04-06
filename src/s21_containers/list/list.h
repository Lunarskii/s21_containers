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
        class ListConstIterator;
    
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using const_pointer  = const T*;
        using iterator = List<T>::ListIterator;
        using const_iterator = List<T>::ListConstIterator;
        using size_type = std::size_t;


        /*                  CONSTRUCTORS/DESTRUCTORS                                            */
        List();                                              // default constructor, creates an empty list
        List(size_type n);                                   // parameterized constructor, creates the list of size n
        List(std::initializer_list<value_type> const &items);// initializer list constructor, creates a list initizialized using std::initializer_list
        List(const List &other);                             // copy constructor 
        List(List &&other);                                  // move constructor      
        ~List();                                             // destructor

        /*                  METHODS                                                             */
        size_type max_size();                                   // returns the maximum possible number of elements
        size_type size();                                       // returns the number of elements
        iterator insert(iterator pos, const_reference value);   // inserts elements into concrete pos and returns the iterator that points to the new element
        iterator begin();                                       // returns an iterator to the beginning
        const_iterator begin() const;
        iterator end();                                         // returns an iterator to the end
        const_iterator end() const;
        const_reference front();                                // access the first element
        const_reference back();                                 // access the last element
        bool empty();                                           // checks whether the container is empty
        void erase(iterator pos);                               // erases an element at pos
        void clear();                                           // clears the contents
        void reverse();                                         // reverses the order of the elements
        void swap(List& other);                                 // swaps the contents
        void push_back(const_reference value);                  // adds an element to the end
        void pop_back();                                        // removes the last element
        void push_front(const_reference value);                 // adds an element to the head
        void pop_front();                                       // removes the first element
        void swap_elements(value_type &a, value_type &b);

        /*                  OPERATORS                                                           */             
        List<value_type>& operator=(List &&other);                                 // assignment operator overload for moving an object

    private:
        Node *head{nullptr};
        Node *tail{nullptr};
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
        ListIterator(Node *node, Node *head = nullptr);

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
            
    public: // private
        Node* node_{nullptr};
        Node* head_{nullptr};
};

template <typename value_type>
class List<value_type>::ListConstIterator : public ListIterator { // <value_type>
    public:
        // наследуем конструкторы базового класса
        // using ListIterator::ListIterator;

        // Конструктор с указанием начального узла
        ListConstIterator(Node *node);

        // Операторы инкремента и декремента
        ListConstIterator& operator++();
        ListConstIterator& operator--();
        ListConstIterator operator++(int);
        ListConstIterator operator--(int);

        // Операторы сравнения
        bool operator==(const ListConstIterator& other) const;
        bool operator!=(const ListConstIterator& other) const;

        // Операторы доступа к элементам
        const_reference operator*() const;
        const_pointer operator->() const;

    public: // private
        Node* node_{nullptr};
};

#include "list.tpp"
#include "iterators.tpp"

#endif  // SRC_S21_CONTAINERS_H_LIST_LIST_H_
