#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_H_
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
class vector {
 public:
  class VectorConstIterator;
  class VectorIterator;

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using pointer = T*;
  using const_pointer = const T*;
  using iterator = vector<T>::VectorIterator;
  using const_iterator = vector<T>::VectorConstIterator;
  using size_type = std::size_t;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const& items);
  vector(const vector& v);
  vector(vector&& v);
  ~vector();
  vector& operator=(vector&& v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  pointer data();

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector& other);

  template <typename... Args>
  iterator emplace(iterator pos, Args&&... args);
  template <typename... Args>
  void emplace_back(Args&&... args);

 private:
  pointer data_{nullptr};
  size_type size_{0};
  size_type capacity_{0};
};

template <typename value_type>
class vector<value_type>::VectorIterator {
 public:
  VectorIterator(pointer ptr);

  reference operator*();
  VectorIterator& operator++();
  VectorIterator& operator--();
  VectorIterator operator++(int);
  VectorIterator operator--(int);
  bool operator==(const VectorIterator& other) const;
  bool operator!=(const VectorIterator& other) const;
  VectorIterator operator+(int n) const;
  VectorIterator operator-(int n) const;
  ptrdiff_t operator-(const VectorIterator& other) const;

 private:
  pointer ptr_;
};

template <typename value_type>
class vector<value_type>::VectorConstIterator {
 public:
  VectorConstIterator(const_pointer ptr);

  const_reference operator*() const;
  VectorConstIterator& operator++();
  VectorConstIterator& operator--();
  VectorConstIterator operator++(int);
  VectorConstIterator operator--(int);
  bool operator==(const VectorConstIterator& other) const;
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
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_VECTOR_VECTOR_H_
