

#include <iostream>

template<typename T>
class BinaryTree {
    public:
        class Node;
        class BinaryTreeIterator;
        class BinaryTreeConstIterator;

        using key_type = T;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using const_pointer = const T*;
        using iterator = BinaryTree<T>::BinaryTreeIterator;
        using const_iterator = BinaryTree<T>::BinaryTreeConstIterator;

        /*                  CONSTRUCTORS/DESTRUCTORS                                            */
        BinaryTree();
        BinaryTree(std::initializer_list<value_type> const &items);
        BinaryTree(const BinaryTree& other);
        BinaryTree(BinaryTree&& other);
        ~BinaryTree(); 

        /*                  METHODS                                                             */
        // void insert(value_type data);
        void insert(const_reference data, Node*& node = root, Node* up = nullptr);
        // void remove(value_type data);
        void remove(const_reference data, Node* node = root);
        Node* findMinValue(Node* node);


        void deleteTree(Node *node = root);
        void printTree(Node *node = root);

        iterator begin();
        iterator end();
        // const_iterator cbegin();
        // const_iterator cend();

        


        /*                  OPERATORS                                                           */   

    private:
        Node* root{nullptr};
        // Node* node_{nullptr};
};

template<typename value_type>
class BinaryTree<value_type>::Node {
    public:
        // скорее всего left и right вообще не требуются в конструкторе
        Node(const value_type& d = value_type{}, Node* l = nullptr, Node* r = nullptr, Node* u = nullptr);
        value_type data;
        Node* left;
        Node* right;
        Node* up;
    private:
};

template<typename value_type>
class BinaryTree<value_type>::BinaryTreeIterator {
    public:
        // Конструктор по умолчанию
        BinaryTreeIterator() = default;

        // Конструктор с указанием начального узла
        BinaryTreeIterator(Node *node);

        // Конструктор копирования из BinaryTreeConstIterator
        // BinaryTreeIterator(BinaryTreeConstIterator& it);

        // Операторы инкремента и декремента
        BinaryTreeIterator& operator++();
        BinaryTreeIterator& operator--();
        BinaryTreeIterator operator++(int);
        BinaryTreeIterator operator--(int);

        // Операторы сравнения
        bool operator==(const BinaryTreeIterator& other) const;
        bool operator!=(const BinaryTreeIterator& other) const;

        // Операторы перемещения/сложения
        // BinaryTreeIterator operator+(size_type n) const;
        // BinaryTreeIterator operator-(size_type n) const;

        // Операторы доступа к элементам
        reference operator*() const;
        // pointer operator->() const;
    private:
        Node *node_;
};

template<typename value_type>
class BinaryTree<value_type>::BinaryTreeConstIterator {
    public:
    private:
};

#include "binary_tree.tpp"
#include "iterators.tpp"
#include "const_iterators.tpp"