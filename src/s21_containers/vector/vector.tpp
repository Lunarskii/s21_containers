//==================================================================================
// Member functions
//==================================================================================

template <typename value_type>
Vector<value_type>::Vector() : capacity_(0), size_(0), data_(nullptr) {}

template <typename value_type>
Vector<value_type>::Vector(size_type n)
    : capacity_(n), size_(n), data_(new T[n]) {}

template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const& items)
    : capacity_(items.size()), size_(items.size()), data_(new T[items.size()]) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename value_type>
Vector<value_type>::Vector(const Vector& v)
    : capacity_(v.capacity_), size_(v.size_), data_(new T[v.capacity_]) {
  std::copy(v.data_, v.data_ + v.size_, data_);
}

template <typename value_type>
Vector<value_type>::Vector(Vector&& v)
    : capacity_(v.capacity_), size_(v.size_), data_(v.data_) {
  v.capacity_ = 0;
  v.size_ = 0;
  v.data_ = nullptr;
}

template <typename value_type>
Vector<value_type>::~Vector() {
  delete[] data_;
}

template <typename value_type>
Vector<value_type>& Vector<value_type>::operator=(const Vector& v) {
  if (this == &v) {
    return *this;
  }

  delete[] data_;
  capacity_ = v.capacity_;
  size_ = v.size_;
  data_ = new T[capacity_];
  std::copy(v.data_, v.data_ + v.size_, data_);

  return *this;
}

template <typename value_type>
Vector<value_type>& Vector<value_type>::operator=(Vector&& v) {
  if (this == &v) {
    return *this;
  }

  delete[] data_;
  capacity_ = v.capacity_;
  size_ = v.size_;
  data_ = v.data_;
  v.capacity_ = 0;
  v.size_ = 0;
  v.data_ = nullptr;

  return *this;
}

//==================================================================================
// Element access
//==================================================================================

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Vector index out of range");
  }
  return data_[pos];
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](
    size_type pos) {
  return data_[pos];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::front() const {
  return data_[0];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::back() const {
  return data_[size_ - 1];
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::data() {
  return data_;
}

//==================================================================================
// Vector Iterators
//==================================================================================

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin() {
  return data_;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::end() {
  return data_ + size_;
}

template <typename value_type>
typename Vector<value_type>::const_iterator Vector<value_type>::begin() const {
  return data_;
}

template <typename value_type>
typename Vector<value_type>::const_iterator Vector<value_type>::end() const {
  return data_ + size_;
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
  return std::numeric_limits<size_type>::max();
}

template <typename value_type>
void Vector<value_type>::reserve(size_type new_capacity) {
  if (new_capacity <= capacity_) {
    return;
  }

  T* new_data = new T[new_capacity];
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
  if (capacity_ == size_) {
    return;
  }

  T* new_data = new T[size_];
  std::copy(data_, data_ + size_, new_data);
  delete[] data_;
  data_ = new_data;
  capacity_ = size_;
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
  size_type index = pos - data_;
  if (size_ == capacity_) {
    reserve(capacity_ * 2);
  }

  for (size_type i = size_; i > index; --i) {
    data_[i] = data_[i - 1];
  }
  data_[index] = value;
  ++size_;
  return data_ + index;
}

template <typename value_type>
void Vector<value_type>::erase(iterator pos) {
  size_type index = pos - data_;
  for (size_type i = index; i < size_ - 1; ++i) {
    data_[i] = data_[i + 1];
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
  std::swap(capacity_, other.capacity_);
  std::swap(size_, other.size_);
  std::swap(data_, other.data_);
}
