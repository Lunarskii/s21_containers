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

//==================================================================================
// VectorConstIterator
//==================================================================================

template <typename value_type>
Vector<value_type>::VectorConstIterator::VectorConstIterator(const_pointer ptr)
    : ptr_(ptr) {}

template <typename value_type>
typename Vector<value_type>::const_reference
Vector<value_type>::VectorConstIterator::operator*() const {
  return *ptr_;
}

template <typename value_type>
typename Vector<value_type>::VectorConstIterator&
Vector<value_type>::VectorConstIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename value_type>
typename Vector<value_type>::VectorConstIterator&
Vector<value_type>::VectorConstIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename value_type>
typename Vector<value_type>::VectorConstIterator
Vector<value_type>::VectorConstIterator::operator++(int) {
  VectorConstIterator temp(*this);
  ++ptr_;
  return temp;
}

template <typename value_type>
typename Vector<value_type>::VectorConstIterator
Vector<value_type>::VectorConstIterator::operator--(int) {
  VectorConstIterator temp(*this);
  --ptr_;
  return temp;
}

template <typename value_type>
bool Vector<value_type>::VectorConstIterator::operator==(
    const VectorConstIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename value_type>
bool Vector<value_type>::VectorConstIterator::operator!=(
    const VectorConstIterator& other) const {
  return ptr_ != other.ptr_;
}

}  // namespace s21
#endif  // SRC_S21_CONTAINERS_H_VECTOR_VECTOR_ITERATORS_TPP_
