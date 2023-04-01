#ifndef SRC_S21_CONTAINERS_H_LIST_LIST_H_
#define SRC_S21_CONTAINERS_H_LIST_LIST_H_

// не могу никак без public реализовать
class Node {
    public:
        Node(double data);
        double data;
        Node *prev;
        Node *next;
};

class S21List {
    public:
        S21List();   // constructor
        ~S21List();  // destructor

        Node *push_front(double data);
        Node *push_back(double data);
        void pop_front();
        void pop_back();
        Node* getAt(int index);
        Node* insert(int index, double data);
        void erase(int index);

        Node* operator[](int index);

    private:
        Node *head;
        Node *tail;
};

#endif  // SRC_S21_CONTAINERS_H_LIST_LIST_H_
