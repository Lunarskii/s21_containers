#ifndef SRC_S21_CONTAINERS_H_VECTOR_VECTOR_ITERATORS_TPP_
#define SRC_S21_CONTAINERS_H_VECTOR_VECTOR_ITERATORS_TPP_
namespace s21 {

//==================================================================================
// VectorIterator
//==================================================================================

template <typename value_type>
Vector<value_type>::VectorIterator::VectorIterator(pointer ptr) : ptr_(ptr) {}

template <typename value_type>
typename Vector<value_type>::reference
Vector<value_type>::VectorIterator::operator*() {
  return *ptr_;
}

template <typename value_type>
typename Vector<value_type>::VectorIterator&
Vector<value_type>::VectorIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename value_type>
typename Vector<value_type>::VectorIterator&
Vector<value_type>::VectorIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename value_type>
typename Vector<value_type>::VectorIterator
Vector<value_type>::VectorIterator::operator++(int) {
  VectorIterator temp(*this);
  ++ptr_;
  return temp;
}

template <typename value_type>
typename Vector<value_type>::VectorIterator
Vector<value_type>::VectorIterator::operator--(int) {
  VectorIterator temp(*this);
  --ptr_;
  return temp;
}

template <typename value_type>
bool Vector<value_type>::VectorIterator::operator==(
    const VectorIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename value_type>
bool Vector<value_type>::VectorIterator::operator!=(
    const VectorIterator& other) const {
  return ptr_ != other.ptr_;
}

// template <typename value_type>
// typename Vector<value_type>::VectorIterator
// Vector<value_type>::VectorIterator::operator+(int n) const {
//   VectorIterator temp = *this;
//   temp.current += n;
//   return temp;
// }

// template <typename value_type>
// typename Vector<value_type>::VectorIterator
// Vector<value_type>::VectorIterator::operator-(int n) const {
//   VectorIterator temp = *this;
//   temp.current -= n;
//   return temp;
// }

//==================================================================================
// VectorConstIterator
//==================================================================================

// Constructor
template <typename value_type>
Vector<value_type>::VectorConstIterator::VectorConstIterator(const_pointer ptr)
    : BaseIterator(ptr) {}

// Access the element pointed to by the iterator
template <typename value_type>
typename Vector<value_type>::VectorConstIterator::const_reference
Vector<value_type>::VectorConstIterator::operator*() const {
  return BaseIterator::operator*();
}

// Все остальные методы VectorConstIterator наследуются от VectorIterator,
// поэтому их не нужно определять здесь.

}  // namespace s21
#endif  // SRC_S21_CONTAINERS_H_VECTOR_VECTOR_ITERATORS_TPP_
