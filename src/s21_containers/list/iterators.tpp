#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_ITERATORS_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_ITERATORS_TPP_

namespace s21 {
template<typename value_type>
list<value_type>::ListIterator::ListIterator(Node *node, Node *head, Node *tail)
    : node_(node)
    , head_(head)
    , tail_(tail)
{}

template<typename value_type>
list<value_type>::ListIterator::ListIterator(ListConstIterator& it)
    : node_(it.it_.node_)
{}

template<typename value_type>
typename list<value_type>::ListIterator& list<value_type>::ListIterator::operator++()
{
    if (head_ != nullptr)
    {
        if (node_ != nullptr)
        {
            node_ = node_->next;
        }
        else
        {
            node_ = head_;
        }
    }
    return *this;
}

template<typename value_type>
typename list<value_type>::ListIterator& list<value_type>::ListIterator::operator--()
{
    if (tail_ != nullptr)
    {
        if (node_ != nullptr)
        {
            if (node_->prev != nullptr)
            {
                node_ = node_->prev;
            }
            else
            {
                node_ = tail_->next;
            }
        }
        else
        {
            node_ = tail_;
        }
    }
    return *this;
}

template<typename value_type>
typename list<value_type>::ListIterator list<value_type>::ListIterator::operator++(int)
{
    ListIterator it(*this);
    ++(*this);
    return it;
}

template<typename value_type>
typename list<value_type>::ListIterator list<value_type>::ListIterator::operator--(int)
{
    ListIterator it(*this);
    --(*this);
    return it;
}

template<typename value_type>
bool list<value_type>::ListIterator::operator==(const ListIterator& other) const
{
    return node_ == other.node_;
}

template<typename value_type>
bool list<value_type>::ListIterator::operator!=(const ListIterator& other) const
{
    return !(*this == other);
}

template<typename value_type>
typename list<value_type>::ListIterator list<value_type>::ListIterator::operator+(size_type n) const
{
    ListIterator it(*this);
    for (; n != 0; --n) ++it;
    return it;
}

template<typename value_type>
typename list<value_type>::ListIterator list<value_type>::ListIterator::operator-(size_type n) const
{
    ListIterator it(*this);
    for (; n != 0; --n) --it;
    return it;
}

template<typename value_type>
typename list<value_type>::reference list<value_type>::ListIterator::operator*() const
{
    if (node_ == nullptr && tail_ != nullptr) // это если мы пытаемся разыменовать tail_->next, который в оригинале дублирует значение из tail_
    {
        return tail_->data;
    }
    else if (node_ != nullptr)
    {
        return node_->data;
    }
    else
    {
        throw std::invalid_argument("Invalid index");
    }
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_ITERATORS_TPP_
