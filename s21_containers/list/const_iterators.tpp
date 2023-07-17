#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_CONST_ITERATORS_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_CONST_ITERATORS_TPP_

namespace s21 {
template<typename value_type>
list<value_type>::ListConstIterator::ListConstIterator(const ListIterator& it)
    : it_(it)
{}

template<typename value_type>
list<value_type>::ListConstIterator::ListConstIterator(Node* node, Node* head, Node* tail)
    : it_(node, head, tail)
{}

template<typename value_type>
typename list<value_type>::ListConstIterator& list<value_type>::ListConstIterator::operator++()
{
    ++it_; 
    return *this; 
}

template<typename value_type>
typename list<value_type>::ListConstIterator& list<value_type>::ListConstIterator::operator--()
{
    --it_; 
    return *this; 
}

template<typename value_type>
typename list<value_type>::ListConstIterator list<value_type>::ListConstIterator::operator++(int)
{
    ListConstIterator tmp(*this); 
    ++it_; 
    return tmp; 
}

template<typename value_type>
typename list<value_type>::ListConstIterator list<value_type>::ListConstIterator::operator--(int)
{
    ListConstIterator tmp(*this); 
    --it_; 
    return tmp; 
}

template<typename value_type>
bool list<value_type>::ListConstIterator::operator==(const ListConstIterator& other) const
{
    return it_ == other.it_; 
}

template<typename value_type>
bool list<value_type>::ListConstIterator::operator!=(const ListConstIterator& other) const
{
    return !(it_ == other.it_);
}

template<typename value_type>
typename list<value_type>::const_reference list<value_type>::ListConstIterator::operator*() const
{
    return *it_; 
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_LIST_CONST_ITERATORS_TPP_
