#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_H_

#include <cstddef>
#include <initializer_list>
#include <limits>
#include <algorithm>

namespace s21 {
template <typename T>
class List
{
public:
    class Node;
    class ListIterator;
    class ListConstIterator;

    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = List<T>::ListIterator;
    using const_iterator = List<T>::ListConstIterator;
    using size_type = std::size_t;

    /*                  CONSTRUCTORS/DESTRUCTORS                                            */
    List();                                                 // default constructor, creates an empty list
    List(size_type n);                                      // parameterized constructor, creates the list of size n
    List(std::initializer_list<value_type> const &items);   // initializer list constructor, creates a list initizialized using std::initializer_list
    List(const List &other);                                // copy constructor
    List(List &&other);                                     // move constructor
    ~List();                                                // destructor

    /*                  METHODS                                                             */
    size_type max_size();                                   // returns the maximum possible number of elements
    size_type size();                                       // returns the number of elements
    iterator insert(iterator pos, const_reference value);   // inserts elements into concrete pos and returns the iterator that points to the new element
    iterator begin();                                       // returns an iterator to the beginning
    iterator end();                                         // returns an iterator to the end
    const_iterator cbegin() const;                           // returns an const iterator to the beginning
    const_iterator cend() const;                             // returns an const iterator to the end
    const_reference front();                                // access the first element
    const_reference back();                                 // access the last element
    bool empty();                                           // checks whether the container is empty
    void splice(const_iterator pos, List& other);           // transfers elements from list other starting from pos
    void unique();                                          // removes consecutive duplicate elements
    void merge(List& other);                                // merges two sorted lists
    void sort();                                            // sorts the elements
    void erase(iterator pos);                               // erases an element at pos
    void clear();                                           // clears the contents
    void reverse();                                         // reverses the order of the elements
    void swap(List& other);                                 // swaps the contents
    void push_back(const_reference value);                  // adds an element to the end
    void pop_back();                                        // removes the last element
    void push_front(const_reference value);                 // adds an element to the head
    void pop_front();                                       // removes the first element

    template <typename... Args>
    void emplace_back(Args&&... args);                      // appends new elements to the end of the container

    template <typename... Args>
    void emplace_front(Args&&... args);                     // appends new elements to the top of the container

    template <typename... Args>
    iterator emplace(const_iterator pos, Args&&... args);   // inserts new elements into the container directly before pos

    /*                  OPERATORS                                                           */
    List& operator=(const List& other);                     // assignment operator overload for moving an object
    List& operator=(List&& other);                          // assignment operator overload for copy an object

private:
    Node *head{nullptr};
    Node *tail{nullptr};
};

template <typename value_type>
class List<value_type>::Node
{
    public:
        Node(const value_type& d = value_type{}, Node* p = nullptr, Node* n = nullptr);
        value_type data;
        Node *prev;
        Node *next;
};

template <typename value_type>
class List<value_type>::ListIterator
{
    public:
        ListIterator() = default;
        ListIterator(Node *node, Node *head = nullptr, Node *tail = nullptr);
        ListIterator(ListConstIterator& it);

        ListIterator& operator++();
        ListIterator& operator--();
        ListIterator operator++(int);
        ListIterator operator--(int);
        bool operator==(const ListIterator& other) const;
        bool operator!=(const ListIterator& other) const;
        ListIterator operator+(size_type n) const;
        ListIterator operator-(size_type n) const;
        reference operator*() const;
            
    public:
        Node* node_{nullptr};
        Node* head_{nullptr};
        Node* tail_{nullptr};
};

template <typename value_type>
class List<value_type>::ListConstIterator : public ListIterator
{
    public:
        ListConstIterator() = default;
        ListConstIterator(const ListIterator& it);
        ListConstIterator(Node* node, Node* head = nullptr, Node* tail = nullptr);

        ListConstIterator& operator++();
        ListConstIterator& operator--();
        ListConstIterator operator++(int);
        ListConstIterator operator--(int);
        bool operator==(const ListConstIterator& other) const;
        bool operator!=(const ListConstIterator& other) const;
        const_reference operator*() const;

    public:
        ListIterator it_;
};

}  // namespace s21

#include "list.tpp"
#include "iterators.tpp"
#include "const_iterators.tpp"

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_H_
