#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_BINARY_TREE_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_BINARY_TREE_TPP_

template<typename value_type>
BinaryTree<value_type>::Node::Node(const value_type& d, Node* l, Node* r, Node* p) : data(d), left(l), right(r), parent(p) {}

template<typename value_type>
BinaryTree<value_type>::BinaryTree() : root(nullptr) {}

template<typename value_type>
BinaryTree<value_type>::BinaryTree(std::initializer_list<value_type> const &items) {
    for (auto &i : items) {
        insert(i);
    }
}

template<typename value_type>
BinaryTree<value_type>::BinaryTree(const BinaryTree& other) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
        // insert(*it);
        // заменил на мультиинсерт потому что при tree = other.tree 
        // у мультисета происходит исчезновение всех повторяющихся элементов(((
        multiInsert(*it);
    }
}

template<typename value_type>
BinaryTree<value_type>::BinaryTree(BinaryTree&& other) : root(other.root) {
    other.root = nullptr;
}

template<typename value_type>
BinaryTree<value_type>::~BinaryTree() {
    clear(root);
}

template<typename value_type>
std::pair<typename BinaryTree<value_type>::iterator, bool> BinaryTree<value_type>::insert(const_reference data, Node*& node, Node* parent) {
    if (node == nullptr) {
        node = new Node(data, nullptr, nullptr, parent);
        return { iterator(node), true };
    } else {
        if (data < node->data) {
            insert(data, node->left, node);
        } else if (data > node->data) {
            insert(data, node->right, node);
        } else {
            return { iterator(node), false };
        }
    }

    return { iterator(nullptr), false }; // добавил для избежания ошибки, проверить потом чего не хватает
}

template<typename value_type>
std::pair<typename BinaryTree<value_type>::iterator, bool> BinaryTree<value_type>::insert(const_reference data) {
    return insert(data, root, nullptr);
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::multiInsert(const_reference data, Node*& node, Node* parent) {
    if (node == nullptr) {
        node = new Node(data, nullptr, nullptr, parent);
        return iterator(node);
    } else {
        if (data < node->data) {
            multiInsert(data, node->left, node);
        } else if (data > node->data) {
            multiInsert(data, node->right, node);
        } else {
            if (node->left == nullptr) {
                multiInsert(data, node->left, node);
            } else {
                Node* newNode = new Node(data, node->left, nullptr, node);
                node->left->parent = newNode;
                node->left = newNode;
                return iterator(newNode);
            }
        }
    }

    return iterator(nullptr);
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::multiInsert(const_reference data) {
    return multiInsert(data, root, nullptr);
}

template<typename value_type>
typename BinaryTree<value_type>::Node* BinaryTree<value_type>::erase(const_reference data, Node* node) {
    if (node == nullptr) {
        throw std::runtime_error("такого элемента нема");
        // return;
    }

    if (data < node->data) {
        erase(data, node->left);
    } else if (data > node->data) {
        erase(data, node->right);
    } else if (data == node->data) {
        if (node->left == nullptr && node->right == nullptr) {
            Node* parent = node->parent;
            
            if (parent != nullptr) {
                if (data > parent->data) {
                    parent->right = nullptr;
                } else if (data < parent->data) {
                    parent->left = nullptr;
                }
            } else {
                root = nullptr;
            }

            delete node;
        } else if (node->left == nullptr) {
            Node* parent = node->parent;
            Node* temp = node;

            if (parent != nullptr) {
                if (data > parent->data) {
                    parent->right = node->right;
                } else if (data < parent->data) {
                    parent->left = node->right;
                }
            } else {
                root = node->right;
            }
            node = node->right;
            node->parent = parent;

            delete temp;
        } else if (node->right == nullptr) {
            Node* parent = node->parent;
            Node* temp = node;

            if (parent != nullptr) {
                if (data > parent->data) {
                    parent->right = node->left;
                } else if (data < parent->data) {
                    parent->left = node->left;
                }
            } else {
                root = node->left;
            }
            node = node->left;
            node->parent = parent;

            delete temp;
        } else {
            Node* temp = findMinValue(node->right);
            node->data = temp->data;
            ++temp->data; // для того чтобы родитель различался от узла, с которым меняются
            node->right = erase(temp->data, node->right);
        }
    } else {
        throw std::runtime_error("data not found");
        // Если такого элемента нет
    }

    return node; // добавил для избежания ошибки, проверить потом чего не хватает
}

template<typename value_type>
void BinaryTree<value_type>::erase(const_reference data) {
    erase(data, root);
}

template<typename value_type>
bool BinaryTree<value_type>::empty() const {
    return root == nullptr;
}

template<typename value_type>
typename BinaryTree<value_type>::size_type BinaryTree<value_type>::size() const {
    size_type size = 0;

    for (iterator it = begin(); it != end(); ++it) {
        ++size;
    }

    return size;
}

template<typename value_type>
typename BinaryTree<value_type>::size_type BinaryTree<value_type>::max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(Node) / 3;
}

template<typename value_type>
void BinaryTree<value_type>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<typename value_type>
void BinaryTree<value_type>::clear() {
    clear(root);
    root = nullptr;
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::find(const_reference key) {
    Node* node = root;

    while (node != nullptr) {
        if (key < node->data) {
            node = node->left;
        } else if (key > node->data) {
            node = node->right;
        } else if (key == node->data) {
            while (node->left != nullptr && node->left->data == key) {
                node = node->left;
            }
            return iterator(node);
        }
    }

    return iterator(end());
}

template<typename value_type>
bool BinaryTree<value_type>::contains(const_reference key) {
    Node* node = root;

    while (node != nullptr) {
        if (key < node->data) {
            node = node->left;
        } else if (key > node->data) {
            node = node->right;
        } else if (key == node->data) {
            return true;
        }
    }

    return false;
}

/**
 * 
 * STL:
 * 
 * Процесс слияния начинается с наименьшего элемента каждого множества. 
 * Сравниваются два наименьших элемента, и наименьший из них добавляется в результирующее множество. 
 * Затем процесс повторяется для следующих двух наименьших элементов, 
 * и так далее, пока все элементы не будут добавлены в результирующее множество.
 * 
 * Примечание: Если элементы в двух множествах имеют одинаковый ключ, то слияния не происходит и данный элемент
 * не будет перемещен(удален во втором множестве т.е.)
 * 
*/
template<typename value_type>
void BinaryTree<value_type>::merge(BinaryTree& other) {   
    for (iterator it = other.begin(); it != other.end(); ++it) {
        if (!contains(*it)) {
            insert(*it);
            other.erase(*it);
        }
    }
}

template<typename value_type>
void BinaryTree<value_type>::multiMerge(BinaryTree& other) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
        multiInsert(*it);
    }
    other.clear();
}

template<typename value_type>
typename BinaryTree<value_type>::size_type BinaryTree<value_type>::count(const_reference key) {
    size_type n = 0;

    for (iterator it = find(key); it != end() && *it == key; ++it, ++n) {}

    return n;
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::lower_bound(const_reference key) {
    iterator it = begin();

    for (; it != end() && *it < key; ++it) {}

    return it;
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::upper_bound(const_reference key) {
    iterator it = begin();

    for (; it != end() && *it <= key; ++it) {}

    return it;
}

template<typename value_type>
template <typename... Args>
std::pair<typename BinaryTree<value_type>::iterator, bool> BinaryTree<value_type>::emplace(Args&&... args) {
    std::pair<iterator, bool> it;

    for (auto &&item : {std::forward<Args>(args)...}) {
        it = insert(item);
    }

    return it;
}

template<typename value_type>
template <typename... Args>
std::pair<typename BinaryTree<value_type>::iterator, bool> BinaryTree<value_type>::multiEmplace(Args&&... args) {
    iterator it;

    for (auto &&item : {std::forward<Args>(args)...}) {
        it = multiInsert(item);
    }

    return { it, true };
}

template<typename value_type>
typename BinaryTree<value_type>::Node* BinaryTree<value_type>::findMinValue(Node* node) {
    Node* temp = node;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

template<typename value_type>
typename BinaryTree<value_type>::Node* BinaryTree<value_type>::findMaxValue(Node* node) {
    Node* temp = node;
    while (temp->right != nullptr) {
        temp = temp->right;;
    }
    return temp;
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::begin() const {
    if (root != nullptr) {
        return iterator(findMinValue(root), root);
    } else {
        return iterator(nullptr);
    }
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::end() const {
    return iterator(nullptr, root);
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTree& BinaryTree<value_type>::operator=(const BinaryTree& other) {
    if (this != &other) {
        clear();
        new (this) BinaryTree(other);
    }

    return *this;
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTree& BinaryTree<value_type>::operator=(BinaryTree&& other) {
    if (this != &other) {
        clear();
        new (this) BinaryTree(std::move(other));
    }

    return *this;
}

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_BINARY_TREE_TPP_
