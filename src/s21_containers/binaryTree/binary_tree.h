

#include <limits>

template<typename T>
class BinaryTree {
    public:
        class Node;
        class BinaryTreeIterator;

        using key_type = T;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using const_pointer = const T*;
        using iterator = BinaryTree<T>::BinaryTreeIterator;
        using size_type = std::size_t;
        // using const_iterator = BinaryTree<T>::BinaryTreeConstIterator;

        /*                  CONSTRUCTORS/DESTRUCTORS                                            */
        BinaryTree();
        BinaryTree(std::initializer_list<value_type> const &items);
        BinaryTree(const BinaryTree& other);
        BinaryTree(BinaryTree&& other);
        ~BinaryTree(); 

        /*                  METHODS                                                             */
        std::pair<iterator, bool> insert(const_reference data, Node*& node, Node* parent = nullptr);
        std::pair<iterator, bool> insert(const_reference data);
        Node* erase(const_reference data, Node* node);
        void erase(const_reference data);
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void clear(Node* node);
        void clear();
        iterator find(const_reference key);
        bool contains(const_reference key);
        void merge(BinaryTree& other);

        
        template <typename... Args>
        std::pair<iterator, bool> emplace(Args&&... args);


        static Node* findMinValue(Node* node);
        static Node* findMaxValue(Node* node);

        iterator begin() const;
        iterator end() const;



        /*                  OPERATORS                                                           */   
        BinaryTree& operator=(const BinaryTree& other);
        BinaryTree& operator=(BinaryTree&& other);

    private:
        Node* root{nullptr};
};

template<typename value_type>
class BinaryTree<value_type>::Node {
    public:
        // скорее всего left и right вообще не требуются в конструкторе
        Node(const value_type& d = value_type{}, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr);
        value_type data;
        Node* left;
        Node* right;
        Node* parent;
    private:
};

template<typename value_type>
class BinaryTree<value_type>::BinaryTreeIterator {
    public:
        // Конструктор по умолчанию
        BinaryTreeIterator() = default;

        // Конструктор с указанием начального узла
        BinaryTreeIterator(Node* node, Node* root = nullptr);

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
        const_reference operator*() const;
        // pointer operator->() const;
    private:
        Node* node_{nullptr};
        Node* root_{nullptr};
};

#include "binary_tree.tpp"
#include "iterators.tpp"