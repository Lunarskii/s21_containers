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

template <class T>
class VectorIterator;

template <class T>
class VectorConstIterator;

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
  void reserve(size_type size);  // mb make it privat?
  size_type capacity() const;
  void shrink_to_fit();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector& other);

  //>>>>>>>>>>>>>>>bonus part<<<<<<<<<<<<<<<<
  template <typename... Args>
  iterator emplace(iterator pos, Args&&... args);

  template <typename... Args>
  void emplace_back(Args&&... args);
  //>>>>>>>>>>>>>>>bonus part<<<<<<<<<<<<<<<<

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

  VectorIterator operator+(int n) const;
  VectorIterator operator-(int n) const;
  ptrdiff_t operator-(const VectorIterator& other) const;

 private:
  pointer ptr_;
};

template <typename value_type>
class Vector<value_type>::VectorConstIterator {
 public:
  // Constructor
  VectorConstIterator(const_pointer ptr);

  // Access the element pointed to by the iterator
  const_reference operator*() const;

  // Move the iterator forward to the next element
  VectorConstIterator& operator++();

  // Move the iterator backward to the previous element
  VectorConstIterator& operator--();

  // Post-increment iterator
  VectorConstIterator operator++(int);

  // Post-decrement iterator
  VectorConstIterator operator--(int);

  // Compare two iterators for equality
  bool operator==(const VectorConstIterator& other) const;

  // Compare two iterators for inequality
  bool operator!=(const VectorConstIterator& other) const;

  VectorConstIterator operator+(int n) const;
  VectorConstIterator operator-(int n) const;
  ptrdiff_t operator-(const VectorConstIterator& other) const;

 private:
  const_pointer ptr_;
};

}  // namespace s21
#include "vector.tpp"
#include "vector_iterators.tpp"
#endif  // SRC_S21_CONTAINERS_H_VECTOR_VECTOR_H_
