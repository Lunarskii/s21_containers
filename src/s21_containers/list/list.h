#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_H_

#include <cstddef>
#include <initializer_list>
#include <limits>
#include <algorithm>

namespace s21 {
template <typename T>
class list
{
public:
    class Node;
    class ListIterator;
    class ListConstIterator;

    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = list<T>::ListIterator;
    using const_iterator = list<T>::ListConstIterator;
    using size_type = std::size_t;

    list();
    list(size_type n);
    list(std::initializer_list<value_type> const &items);
    list(const list &other);
    list(list &&other);
    ~list();

    size_type max_size();
    size_type size();
    iterator insert(iterator pos, const_reference value);
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    const_reference front();
    const_reference back();
    bool empty();
    void splice(const_iterator pos, list& other);
    void unique();
    void merge(list& other);
    void sort();
    void erase(iterator pos);
    void clear();
    void reverse();
    void swap(list& other);
    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();

    template <typename... Args>
    void emplace_back(Args&&... args);
    template <typename... Args>
    void emplace_front(Args&&... args);
    template <typename... Args>
    iterator emplace(const_iterator pos, Args&&... args);

    list& operator=(const list& other);
    list& operator=(list&& other);

private:
    Node *head{nullptr};
    Node *tail{nullptr};
};

template <typename value_type>
class list<value_type>::Node
{
    public:
        Node(const value_type& d = value_type{}, Node* p = nullptr, Node* n = nullptr);
        value_type data;
        Node *prev;
        Node *next;
};

template <typename value_type>
class list<value_type>::ListIterator
{
public:
    friend class list;

    ListIterator() = default;
    ListIterator(const ListConstIterator& it);
    ListIterator(Node *node, Node *head = nullptr, Node *tail = nullptr);

    ListIterator& operator++();
    ListIterator& operator--();
    ListIterator operator++(int);
    ListIterator operator--(int);
    bool operator==(const ListIterator& other) const;
    bool operator!=(const ListIterator& other) const;
    ListIterator operator+(size_type n) const;
    ListIterator operator-(size_type n) const;
    reference operator*() const;

private:
    Node* node_{nullptr};
    Node* head_{nullptr};
    Node* tail_{nullptr};
};

template <typename value_type>
class list<value_type>::ListConstIterator : public ListIterator
{
public:
    friend class list;

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

private:
    ListIterator it_;
};

}  // namespace s21

#include "list.tpp"
#include "iterators.tpp"
#include "const_iterators.tpp"

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_LIST_H_
