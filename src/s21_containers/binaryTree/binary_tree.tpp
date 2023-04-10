

template<typename value_type>
BinaryTree<value_type>::Node::Node(const value_type& d, Node* l, Node* r, Node* u) : data(d), left(l), right(r), up(u) {}

template<typename value_type>
BinaryTree<value_type>::BinaryTree() : root(nullptr) {}

template<typename value_type>
BinaryTree<value_type>::BinaryTree() {
    deleteTree();
}

// template<typename value_type>
// void BinaryTree<value_type>::insert(value_type data) {
//     if (root == nullptr) {
//         root = new Node(data);
//     } else {
//         Node* node_ = root;
//         Node* parent_ = nullptr;

//         while (node_ != nullptr || data != node_->data) {
//             parent_ = node_;
//             if (data < node_->data) {
//                 node_ = node_->left;
//             } else if (data > node_->data) {
//                 node_ = node_->right;
//             }
//         }
//         if (node_ == nullptr) {
//             node_ = new Node(data);
//             node_->up = parent_;
//         }
//     }
// }

template<typename value_type>
void BinaryTree<value_type>::insert(const_reference data, Node*& node, Node* up) {
    if (node == nullptr) {
        if (up == nullptr) {
            node = new Node(data);
        } else {
            node = new Node(data, nullptr, nullptr, up);
        }
    } else {
        if (data < node->data) {
            insert(data, node->left, node);
        } else if (data > node->data) {
            insert(data, node->right, node);
        }
    }
}

// template<typename value_type>
// void BinaryTree<value_type>::remove(value_type data) {
//     if (root != nullptr) {
//         Node* node_ = root;

//         while (node_ != nullptr || data != node_->data) {
//             if (data < node_->data) {
//                 node_ = node_->left;
//             } else if (data > node_->data) {
//                 node_ = node_->right;
//             }
//         }
//         if (node_ != nullptr && data == node_->data) {

//         }
//     }
// }

template<typename value_type>
void BinaryTree<value_type>::remove(const_reference data, Node* node) {
    if (node == nullptr) {
        return;
    }

    if (data < node->data) {
        remove(data, node->left);
    } else if (data > node->data) {
        remove(data, node->right);
    } else {
        if (data == node->data) {
            Node* tempNode = node;

            
        } else {
            return; // не дописано возвращение булевого значения false
        }
    }
}

// метод немного не ищет минимальное, я его для ремува использовал .-.
template<typename value_type>
typename BinaryTree<value_type>::Node* BinaryTree<value_type>::findMinValue(Node* node) {
    if (node->left != nullptr) {
        return findMinValue(node->left);
    }
}

template<typename value_type>
void BinaryTree<value_type>::deleteTree(Node *node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template<typename value_type>
void BinaryTree<value_type>::printTree(Node *node) {
    if (node != nullptr) {
        printTree(node->left);
        printTree(node->right);
        std::cout << node->data << std::endl;
    }
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::begin() {
    if (root != nullptr) {
        Node* node = root;

        while (node->left != nullptr) {
            node = node->left;
        }
        return iterator(node);
    } else {
        return iterator(nullptr);
    }
}

template<typename value_type>
typename BinaryTree<value_type>::iterator BinaryTree<value_type>::end() {
    if (root != nullptr) {
        Node* node = root;

        while (node->right != nullptr) {
            node = node->right;
        }
        return iterator(node);
    } else {
        return iterator(nullptr);
    }
}

