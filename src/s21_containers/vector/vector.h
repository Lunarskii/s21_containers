#ifndef SRC_S21_CONTAINERS_H_VECTOR_VECTOR_H_
#define SRC_S21_CONTAINERS_H_VECTOR_VECTOR_H_
#pragma once

#include <cstddef>
#include <initializer_list>

template <typename T>
class Vector {
 public:
  // Member types
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = std::size_t;

  // Member functions
  Vector();                      // default constructor
  explicit Vector(size_type n);  // parameterized constructor
  Vector(std::initializer_list<value_type> const&
             items);        // initializer list constructor
  Vector(const Vector& v);  // copy constructor
  Vector(Vector&& v);       // move constructor
  ~Vector();                // destructor

  Vector& operator=(const Vector& v);  // copy assignment operator
  Vector& operator=(Vector&& v);       // move assignment operator

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
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
  size_type capacity_;
  size_type size_;
  T* data_;
};

#include "vector.tpp"

#endif  // SRC_S21_CONTAINERS_H_VECTOR_VECTOR_H_
