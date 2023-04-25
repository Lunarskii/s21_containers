#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_TPP_

namespace s21 {
//==================================================================================
// Member functions
//==================================================================================

template <typename value_type>
Vector<value_type>::Vector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename value_type>
Vector<value_type>::Vector(size_type n)
    : data_(new value_type[n]), size_(n), capacity_(n) {
  std::fill_n(data_, n, value_type());
}

template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const& items)
    : data_(new value_type[items.size()]),
      size_(items.size()),
      capacity_(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename value_type>
Vector<value_type>::Vector(const Vector& v)
    : data_(new value_type[v.capacity_]),
      size_(v.size_),
      capacity_(v.capacity_) {
  std::copy(v.data_, v.data_ + v.size_, data_);
}

template <typename value_type>
Vector<value_type>::Vector(Vector&& v)
    : data_(v.data_), size_(v.size_), capacity_(v.capacity_) {
  v.data_ = nullptr;
  v.size_ = 0;
  v.capacity_ = 0;
}

template <typename value_type>
Vector<value_type>::~Vector() {
  delete[] data_;
}

template <typename value_type>
Vector<value_type>& Vector<value_type>::operator=(Vector&& v) {
  if (this != &v) {
    delete[] data_;
    data_ = v.data_;
    size_ = v.size_;
    capacity_ = v.capacity_;

    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }
  return *this;
}

//==================================================================================
// Element access
//==================================================================================

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Vector::at() - Index out of range");
  }
  return data_[pos];
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](
    size_type pos) {
  return data_[pos];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::operator[](
    size_type pos) const {
  return data_[pos];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::front() const {
  if (size_ == 0)
    throw std::out_of_range(
        "s21::vector::front Using methods on a "
        "zero sized container results "
        "in the UB");
  return data_[0];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::back() const {
  if (size_ == 0)
    throw std::out_of_range(
        "s21::vector::front Using methods on a "
        "zero sized container results "
        "in the UB");
  return data_[size_ - 1];
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::data() {
  return iterator(data_);
}

// ==================================================================================
// Vector Iterators
// ==================================================================================

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin() {
  return iterator(data_);
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::end() {
  return iterator(data_ + size_);
}

template <typename value_type>
typename Vector<value_type>::const_iterator Vector<value_type>::begin() const {
  return const_iterator(data_);
}

template <typename value_type>
typename Vector<value_type>::const_iterator Vector<value_type>::end() const {
  return const_iterator(data_ + size_);
}

//==================================================================================
// Vector Capacity
//==================================================================================

template <typename value_type>
bool Vector<value_type>::empty() const {
  return size_ == 0;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::size() const {
  return size_;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template <typename value_type>
void Vector<value_type>::reserve(size_type new_capacity) {
  if (new_capacity <= capacity_) return;

  if (new_capacity > max_size())
    throw std::length_error(
        "s21::vector::reserve Reserve capacity can't be larger than "
        "Vector<T>::max_size()");

  pointer new_data = new value_type[new_capacity];
  std::copy(data_, data_ + size_, new_data);
  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() const {
  return capacity_;
}

template <typename value_type>
void Vector<value_type>::shrink_to_fit() {
  if (capacity_ == size_) return;

  if (size_ < capacity_) {
    pointer new_data = new value_type[size_];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

//==================================================================================
// Vector Modifiers
//==================================================================================

template <typename value_type>
void Vector<value_type>::clear() {
  size_ = 0;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::insert(
    iterator pos, const_reference value) {
  size_type index = pos - begin();

  if (index > size_)
    throw std::out_of_range(
        "s21::vector::insert Unable to insert into a position out of "
        "range of begin() to end()");

  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }

  iterator new_pos = begin() + index;

  for (iterator it = end(); it != new_pos; --it) {
    *it = *(it - 1);
  }

  *new_pos = value;
  ++size_;
  return new_pos;
}

template <typename value_type>
void Vector<value_type>::erase(iterator pos) {
  for (iterator it = pos; it != end() - 1; ++it) {
    *it = *(it + 1);
  }
  --size_;
}

template <typename value_type>
void Vector<value_type>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }
  data_[size_++] = value;
}

template <typename value_type>
void Vector<value_type>::pop_back() {
  if (size_ > 0) {
    --size_;
  }
}

template <typename value_type>
void Vector<value_type>::swap(Vector& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

//==================================================================================
// Vector bonus part
//==================================================================================

template <typename value_type>
template <typename... Args>
typename Vector<value_type>::iterator Vector<value_type>::emplace(
    iterator pos, Args&&... args) {
  // size_type index = pos - begin();
  // if (size_ + 1 > capacity_) {
  //   reserve(capacity_ * 2);
  // }
  // for (size_type i = size_; i > index; --i) {
  //   data_[i] = std::move(data_[i - 1]);
  // }
  // new (data_ + index) value_type(std::forward<Args>(args)...);
  // ++size_;
  // return iterator(data_ + index);

  auto args_v = std::initializer_list<value_type>{std::forward<Args>(args)...};

  for (auto& i : args_v) {
    insert(pos, i);
  }

  return pos;

  // iterator ret = nullptr;
  // auto id = pos - begin();
  // reserve(capacity_ + sizeof...(args));

  // for (auto&& item : {std::forward<Args>(args)...})
  //   ret = insert(begin() + id, item);

  // return ret;
}

template <typename value_type>
template <typename... Args>
void Vector<value_type>::emplace_back(Args&&... args) {
  // if (size_ + 1 > capacity_) {
  //   reserve(capacity_ * 2);
  // }
  // if (data_) {
  //   new (data_ + size_) value_type(std::forward<Args>(args)...);
  // } else {
  //   data_ = new value_type[1]{std::forward<Args>(args)...};
  // }
  // ++size_;

  emplace(end(), args...);

  // for (auto&& item : {std::forward<Args>(args)...}) {
  //   push_back(item);
  // }
  // return end() - 1;
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_TPP_