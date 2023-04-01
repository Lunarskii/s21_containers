#include "list.h"

Node::Node(double data) {
    this->data = data;
    this->prev = this->next = nullptr;
}

S21List::S21List() : head(nullptr), tail(nullptr) {}

S21List::~S21List() {
    while (head != nullptr) pop_front();
}

Node* S21List::push_front(double data) {
    Node *temp = new Node(data);
    
    temp->next = head;
    if (head != nullptr) head->prev = temp;
    if (tail == nullptr) tail = temp;
    head = temp;

    return temp;
}

Node* S21List::push_back(double data) {
    Node *temp = new Node(data);

    temp->prev = tail;
    if (tail != nullptr) tail->next = temp;
    if (head == nullptr) head = temp;
    tail = temp;

    return temp;
}

void S21List::pop_front() {
    if (head != nullptr) {
        Node *temp = head->next;

        if (temp != nullptr)
            temp->prev = nullptr;
        else
            tail = nullptr;

        delete head;
        head = temp;
    }
}

void S21List::pop_back() {
    if (tail != nullptr) {
        Node *temp = tail->prev;

        if (temp != nullptr)
            temp->next = nullptr;
        else
            head = nullptr;

        delete tail;
        tail = temp;
    }
}

Node* S21List::getAt(int index) {
    Node* ptr = head;
    int n = 0;

    while (n != index) {
        if (ptr == nullptr) return ptr;
        ptr = ptr->next;
        n++;
    }

    return ptr;
}

Node* S21List::operator[](int index) {
    return getAt(index);
}

Node* S21List::insert(int index, double data) {
    Node* right = getAt(index);
    if (right == nullptr)
        return push_back(data);

    Node* left = right->prev;
    if (left == nullptr)
        return push_front(data);

    Node* ptr = new Node(data);
    
    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
}

void S21List::erase(int index) {
    Node* ptr = getAt(index);
    if (ptr == nullptr) return;

    if (ptr->prev == nullptr) {
        pop_front();
        return;
    }

    if (ptr->next == nullptr) {
        pop_back();
        return;
    }

    Node* left = ptr->prev;
    Node* right = ptr->next;
    left->next = right;
    right->prev = left;

    delete ptr;
}
