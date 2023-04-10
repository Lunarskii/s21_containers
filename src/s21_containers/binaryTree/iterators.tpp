



template<typename value_type>
BinaryTree<value_type>::BinaryTreeIterator::BinaryTreeIterator(Node *node)  : node_(node) {}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeIterator& BinaryTree<value_type>::BinaryTreeIterator::operator++() {
    if (node_->left != nullptr) {
        node = node_->left;
    } else if (node_->right != nullptr) {
        node_ = node_->right;
    } else if (node_->up != nullptr) {
        node_ = node_->up;
    }
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeIterator& BinaryTree<value_type>::BinaryTreeIterator::operator--() {

}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeIterator BinaryTree<value_type>::BinaryTreeIterator::operator++(int) {

}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeIterator BinaryTree<value_type>::BinaryTreeIterator::operator--(int) {

}

template<typename value_type>
bool BinaryTree<value_type>::BinaryTreeIterator::operator==(const BinaryTreeIterator& other) const {

}

template<typename value_type>
bool BinaryTree<value_type>::BinaryTreeIterator::operator!=(const BinaryTreeIterator& other) const {

}

template<typename value_type>
typename BinaryTree<value_type>::reference BinaryTree<value_type>::BinaryTreeIterator::operator*() const  {

}

