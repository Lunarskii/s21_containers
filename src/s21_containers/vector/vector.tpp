#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_TPP_

namespace s21 {
//==================================================================================
// Member functions
//==================================================================================

template <typename value_type>
vector<value_type>::vector() {}

template <typename value_type>
vector<value_type>::vector(size_type n)
    : data_(new value_type[n]), size_(n), capacity_(n) {
  std::fill_n(data_, n, value_type());
}

template <typename value_type>
vector<value_type>::vector(std::initializer_list<value_type> const& items)
    : data_(new value_type[items.size()]),
      size_(items.size()),
      capacity_(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename value_type>
vector<value_type>::vector(const vector& v)
    : data_(new value_type[v.capacity_]),
      size_(v.size_),
      capacity_(v.capacity_) {
  std::copy(v.data_, v.data_ + v.size_, data_);
}

template <typename value_type>
vector<value_type>::vector(vector&& v){
    size_ = std::exchange(v.size_, 0);
    capacity_ = std::exchange(v.capacity_, 0);
    data_ = std::exchange(v.data_, nullptr);
}

template <typename value_type>
vector<value_type>::~vector() {
  delete[] data_;
}

template <typename value_type>
vector<value_type>& vector<value_type>::operator=(vector&& v) {
  if (this != &v) {
    clear();
    new (this) vector(std::move(v));
  }
  return *this;
}

//==================================================================================
// Element access
//==================================================================================

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::at(size_type pos) {
  if (pos >= size_ || pos < 0) {
    throw std::out_of_range("vector::at() - Index out of range");
  }
  return data_[pos];
}

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::operator[](
    size_type pos) {
  if (this->size() < pos || 0 > pos) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::operator[](
    size_type pos) const {
  if (this->size() < pos || 0 > pos) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::front() const {
  if (size_ == 0)
    throw std::out_of_range(
        "s21::vector::front Using methods on a "
        "zero sized container results "
        "in the UB");
  return data_[0];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::back() const {
  if (size_ == 0)
    throw std::out_of_range(
        "s21::vector::front Using methods on a "
        "zero sized container results "
        "in the UB");
  return data_[size_ - 1];
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::data() {
  return data_;
}

// ==================================================================================
// vector Iterators
// ==================================================================================

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::begin() {
  return iterator(data_);
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::end() {
  return iterator(data_ + size_);
}

template <typename value_type>
typename vector<value_type>::const_iterator vector<value_type>::begin() const {
  return const_iterator(data_);
}

template <typename value_type>
typename vector<value_type>::const_iterator vector<value_type>::end() const {
  return const_iterator(data_ + size_);
}

//==================================================================================
// vector Capacity
//==================================================================================

template <typename value_type>
bool vector<value_type>::empty() const {
  return size_ == 0;
}

template <typename value_type>
typename vector<value_type>::size_type vector<value_type>::size() const {
  return size_;
}

template <typename value_type>
typename vector<value_type>::size_type vector<value_type>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template <typename value_type>
void vector<value_type>::reserve(size_type new_capacity) {
  if (new_capacity <= capacity_) return;

  if (new_capacity > max_size())
    throw std::length_error(
        "s21::vector::reserve Reserve capacity can't be larger than "
        "vector<T>::max_size()");

  pointer new_data = new value_type[new_capacity];
  std::copy(data_, data_ + size_, new_data);
  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

template <typename value_type>
typename vector<value_type>::size_type vector<value_type>::capacity() const {
  return capacity_;
}

template <typename value_type>
void vector<value_type>::shrink_to_fit() {
if (size_ < capacity_) {
    pointer new_data = new value_type[size_];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

//==================================================================================
// vector Modifiers
//==================================================================================

template <typename value_type>
void vector<value_type>::clear() {
  size_ = 0;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::insert(
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
void vector<value_type>::erase(iterator pos) {
  for (iterator it = pos; it != end() - 1; ++it) {
    *it = *(it + 1);
  }
  --size_;
}

template <typename value_type>
void vector<value_type>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }
  data_[size_++] = value;
}

template <typename value_type>
void vector<value_type>::pop_back() {
  if (size_ > 0) {
    --size_;
  }
}

template <typename value_type>
void vector<value_type>::swap(vector& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

//==================================================================================
// vector bonus part
//==================================================================================

template <typename value_type>
template <typename... Args>
typename vector<value_type>::iterator vector<value_type>::emplace(
    iterator pos, Args&&... args) {
  auto args_v = std::initializer_list<value_type>{std::forward<Args>(args)...};

  for (auto& i : args_v) {
    insert(pos, i);
  }

  return pos;
}

template <typename value_type>
template <typename... Args>
void vector<value_type>::emplace_back(Args&&... args) {
  emplace(end(), args...);
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_TPP_