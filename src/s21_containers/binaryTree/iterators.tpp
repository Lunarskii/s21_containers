#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_ITERATORS_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_ITERATORS_TPP_

namespace s21 {
template<typename value_type>
BinaryTree<value_type>::BinaryTreeIterator::BinaryTreeIterator(Node *node, Node *root) : node_(node), root_(root) {}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeIterator &BinaryTree<value_type>::BinaryTreeIterator::operator++() {
    if (node_->right != nullptr) {
        node_ = BinaryTree::findMinValue(node_->right);
    } else {
        Node *parent = node_->parent;
        while (parent != nullptr && node_ == parent->right) {
            node_ = parent;
            parent = parent->parent;
        }
        node_ = parent;
    }
    return *this;
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeIterator &BinaryTree<value_type>::BinaryTreeIterator::operator--() {
    if (node_ == nullptr && root_ != nullptr) {
        node_ = BinaryTree::findMaxValue(root_);
    } else {
        if (node_->left != nullptr) {
            node_ = BinaryTree::findMaxValue(node_->left);
        } else {
            Node *parent = node_->parent;
            while (parent != nullptr && node_ == parent->left) {
                node_ = parent;
                parent = parent->parent;
            }
            node_ = parent;
        }
    }
    return *this;
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeIterator BinaryTree<value_type>::BinaryTreeIterator::operator++(int) {
    iterator it(*this);
    ++(*this);
    return it;
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeIterator BinaryTree<value_type>::BinaryTreeIterator::operator--(int) {
    iterator it(*this);
    --(*this);
    return it;
}

template<typename value_type>
bool BinaryTree<value_type>::BinaryTreeIterator::operator==(const BinaryTreeIterator &other) const {
    return node_ == other.node_;
}

template<typename value_type>
bool BinaryTree<value_type>::BinaryTreeIterator::operator!=(const BinaryTreeIterator &other) const {
    return !(*this == other);
}

template<typename value_type>
typename BinaryTree<value_type>::const_reference BinaryTree<value_type>::BinaryTreeIterator::operator*() const {
    if (node_ != nullptr) {
        return node_->data;
    } else {
        static const const_reference default_value{};
        return default_value;
        // return size(); если элемента не существует, то нужно вернуть размер бинарного дерева
    }
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_ITERATORS_TPP_
