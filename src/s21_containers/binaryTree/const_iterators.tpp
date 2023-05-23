#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_CONST_ITERATORS_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_CONST_ITERATORS_TPP_

namespace s21 {
template<typename value_type>
BinaryTree<value_type>::BinaryTreeConstIterator::BinaryTreeConstIterator(const BinaryTreeIterator& it)
    : it(it)
{}

template<typename value_type>
BinaryTree<value_type>::BinaryTreeConstIterator::BinaryTreeConstIterator(Node *node, Node *root)
    : it(node, root)
{}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeConstIterator::BinaryTreeConstIterator& BinaryTree<value_type>::BinaryTreeConstIterator::operator++()
{
    ++it;
    return *this;
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeConstIterator::BinaryTreeConstIterator& BinaryTree<value_type>::BinaryTreeConstIterator::operator--()
{
    --it;
    return *this;
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeConstIterator::BinaryTreeConstIterator BinaryTree<value_type>::BinaryTreeConstIterator::operator++(int)
{
    BinaryTreeConstIterator temp(*this);
    ++it;
    return temp;
}

template<typename value_type>
typename BinaryTree<value_type>::BinaryTreeConstIterator::BinaryTreeConstIterator BinaryTree<value_type>::BinaryTreeConstIterator::operator--(int)
{
    BinaryTreeConstIterator temp(*this);
    --it;
    return temp;
}

template<typename value_type>
bool BinaryTree<value_type>::BinaryTreeConstIterator::operator==(const BinaryTreeConstIterator &other) const
{
    return it == other.it;
}

template<typename value_type>
bool BinaryTree<value_type>::BinaryTreeConstIterator::operator!=(const BinaryTreeConstIterator &other) const
{
    return !(it == other.it);
}

template<typename value_type>
typename BinaryTree<value_type>::const_reference BinaryTree<value_type>::BinaryTreeConstIterator::operator*() const
{
    return *it;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_BINARYTREE_CONST_ITERATORS_TPP_
