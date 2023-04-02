#include "list.h"

template<typename value_type>
List<value_type>::Node::Node(const value_type& d, Node* p, Node* n) : data(d), prev(p), next(n) {}

template<typename value_type>
List<value_type>::List() : head(nullptr), tail(nullptr) {}

template<typename value_type>
List<value_type>::~List() {
    while (head != nullptr) pop_front();
}

template<typename value_type>
void List<value_type>::push_front(value_type& data) {
    if (head == nullptr) {
        head = tail = new Node(data);
    } else {
        head->prev = new Node(data, nullptr, head);
        head = head->prev;
    }
}

template<typename value_type>
void List<value_type>::push_back(const value_type& data) {
    if (tail == nullptr) {
        tail = head = new Node(data);
    } else {
        tail->next = new Node(data, tail);
        tail = tail->next;
    }
}

template<typename value_type>
void List<value_type>::pop_front() {
    if (head != nullptr) {
        Node *tempHead = head;

        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete tempHead;
    }
}

template<typename value_type>
void List<value_type>::pop_back() {
    if (tail != nullptr) {
        Node *temp = tail;

        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
    }
}

// template<typename value_type>
// typename S21List<value_type>::Node* S21List<value_type>::getAt(int index) {
//     Node* ptr = head;
//     int n = 0;

//     while (n != index) {
//         if (ptr == nullptr) return ptr;
//         ptr = ptr->next;
//         n++;
//     }

//     return ptr;
// }

// template<typename value_type>
// typename S21List<value_type>::Node* S21List<value_type>::operator[](int index) {
//     return getAt(index);
// }

// template<typename value_type>
// typename S21List<value_type>::Node* S21List<value_type>::insert(int index, double data) {
//     Node* right = getAt(index);
//     if (right == nullptr)
//         return push_back(data);

//     Node* left = right->prev;
//     if (left == nullptr)
//         return push_front(data);

//     Node* ptr = new Node(data);
    
//     ptr->prev = left;
//     ptr->next = right;
//     left->next = ptr;
//     right->prev = ptr;

//     return ptr;
// }

// template<typename value_type>
// void S21List<value_type>::erase(int index) {
//     Node* ptr = getAt(index);
//     if (ptr == nullptr) return;

//     if (ptr->prev == nullptr) {
//         pop_front();
//         return;
//     }

//     if (ptr->next == nullptr) {
//         pop_back();
//         return;
//     }

//     Node* left = ptr->prev;
//     Node* right = ptr->next;
//     left->next = right;
//     right->prev = left;

//     delete ptr;
// }
