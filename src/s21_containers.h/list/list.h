#ifndef SRC_S21_CONTAINERS_H_LIST_LIST_H_
#define SRC_S21_CONTAINERS_H_LIST_LIST_H_

#include <cstddef>

template <typename T>
class List {
    public:
        class Node;
        class ListIterator;
        class ListConstIterator;
    
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = List<T>::ListIterator;
        // using const_iterator = List<const T>::ListConstIterator;
        using size_type = size_t;


        /*                  CONSTRUCTORS/DESTRUCTORS                                            */
        List();                                              // default constructor, creates an empty list
        ~List();                                             // destructor

        void erase(int index);
        // typename S21List<T>::Node* insert(int index, double data);
        void pop_back();
        void pop_front();
        void push_back(const value_type& data);
        void push_front(value_type& data);
    private:
        Node *head;
        Node *tail;
};

template <typename value_type>
class List<value_type>::Node {
    public:
        Node(const value_type& d = value_type{}, Node* p = nullptr, Node* n = nullptr);

    private:
        value_type data;
        Node *prev;
        Node *next;
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
            
    private:
        Node* node_{nullptr};
};

template <typename value_type>
class List<value_type>::ListConstIterator {
    public:
    private:
};

#endif  // SRC_S21_CONTAINERS_H_LIST_LIST_H_
