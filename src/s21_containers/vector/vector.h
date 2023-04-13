#ifndef SRC_S21_CONTAINERS_H_VECTOR_VECTOR_H_
#define SRC_S21_CONTAINERS_H_VECTOR_VECTOR_H_
#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <stdexcept>
#include <utility>

namespace s21 {
template <typename T>
class Vector {
 public:
  class VectorConstIterator;
  class VectorIterator;
  // Member types
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using pointer = T*;
  using const_pointer = const T*;
  using iterator = Vector<T>::VectorIterator;
  using const_iterator = Vector<T>::VectorConstIterator;
  using size_type = size_t;

  // Member functions
  Vector();
  Vector(size_type n);
  Vector(std::initializer_list<value_type> const& items);
  Vector(const Vector& v);
  Vector(Vector&& v);
  ~Vector();
  Vector& operator=(Vector&& v);

  // // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  iterator data();

  // Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector& other);

 private:
  // Private member variables
  pointer data_;
  size_type size_;
  size_type capacity_;
};

template <typename value_type>
class Vector<value_type>::VectorIterator {
 public:
  // Constructor
  VectorIterator(pointer ptr);

  // Access the element pointed to by the iterator
  reference operator*();

  // Move the iterator forward to the next element
  VectorIterator& operator++();

  // Move the iterator backward to the previous element
  VectorIterator& operator--();

  // Post-increment iterator
  VectorIterator operator++(int);

  // Post-decrement iterator
  VectorIterator operator--(int);

  // Compare two iterators for equality
  bool operator==(const VectorIterator& other) const;

  // Compare two iterators for inequality
  bool operator!=(const VectorIterator& other) const;

  // VectorIterator operator+(int n) const;
  // VectorIterator operator-(int n) const;

 private:
  pointer ptr_;
};

template <typename value_type>
class Vector<value_type>::VectorConstIterator
    : public Vector<value_type>::VectorIterator {
 public:
  using BaseIterator = typename Vector<value_type>::VectorIterator;
  using const_reference = typename Vector<value_type>::const_reference;
  using const_pointer = typename Vector<value_type>::const_pointer;

  // Constructor
  // VectorConstIterator(const_pointer ptr) : BaseIterator(ptr) {}
  VectorConstIterator(const_pointer ptr);

  // Access the element pointed to by the iterator
  // const_reference operator*() const { return BaseIterator::operator*(); }
  const_reference operator*() const;

  // No need to re-define other methods, they will be inherited from
  // VectorIterator
};

}  // namespace s21
#include "vector.tpp"
#include "vector_iterators.tpp"
#endif  // SRC_S21_CONTAINERS_H_VECTOR_VECTOR_H_
