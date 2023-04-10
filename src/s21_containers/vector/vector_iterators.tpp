#ifndef SRC_S21_CONTAINERS_H_VECTOR_VECTOR_ITERATORS_TPP_
#define SRC_S21_CONTAINERS_H_VECTOR_VECTOR_ITERATORS_TPP_
namespace s21 {

//==================================================================================
// VectorIterator
//==================================================================================

template <typename value_type>
VectorIterator<value_type>::VectorIterator(pointer ptr) : ptr_(ptr) {}

template <typename value_type>
typename VectorIterator<value_type>::reference
VectorIterator<value_type>::operator*() {
  return *ptr_;
}

template <typename value_type>
VectorIterator<value_type>& VectorIterator<value_type>::operator++() {
  ++ptr_;
  return *this;
}

template <typename value_type>
VectorIterator<value_type>& VectorIterator<value_type>::operator--() {
  --ptr_;
  return *this;
}

template <typename value_type>
VectorIterator<value_type> VectorIterator<value_type>::operator++(int) {
  VectorIterator<value_type> temp(*this);
  ++ptr_;
  return temp;
}

template <typename value_type>
VectorIterator<value_type> VectorIterator<value_type>::operator--(int) {
  VectorIterator<value_type> temp(*this);
  --ptr_;
  return temp;
}

template <typename value_type>
bool VectorIterator<value_type>::operator==(
    const VectorIterator<value_type>& other) const {
  return ptr_ == other.ptr_;
}

template <typename value_type>
bool VectorIterator<value_type>::operator!=(
    const VectorIterator<value_type>& other) const {
  return ptr_ != other.ptr_;
}

//==================================================================================
// VectorConstIterator
//==================================================================================

template <typename value_type>
VectorConstIterator<value_type>::VectorConstIterator(const_pointer ptr)
    : ptr_(ptr) {}

template <typename value_type>
typename VectorConstIterator<value_type>::const_reference
VectorConstIterator<value_type>::operator*() const {
  return *ptr_;
}

template <typename value_type>
VectorConstIterator<value_type>& VectorConstIterator<value_type>::operator++() {
  ++ptr_;
  return *this;
}

template <typename value_type>
VectorConstIterator<value_type>& VectorConstIterator<value_type>::operator--() {
  --ptr_;
  return *this;
}

template <typename value_type>
VectorConstIterator<value_type> VectorConstIterator<value_type>::operator++(
    int) {
  VectorConstIterator<value_type> temp(*this);
  ++ptr_;
  return temp;
}

template <typename value_type>
VectorConstIterator<value_type> VectorConstIterator<value_type>::operator--(
    int) {
  VectorConstIterator<value_type> temp(*this);
  --ptr_;
  return temp;
}

template <typename value_type>
bool VectorConstIterator<value_type>::operator==(
    const VectorConstIterator<value_type>& other) const {
  return ptr_ == other.ptr_;
}

template <typename value_type>
bool VectorConstIterator<value_type>::operator!=(
    const VectorConstIterator<value_type>& other) const {
  return ptr_ != other.ptr_;
}

}  // namespace s21
#endif  // SRC_S21_CONTAINERS_H_VECTOR_VECTOR_ITERATORS_TPP_
