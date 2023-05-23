#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_S21_STACK_H_

#include "../vector/s21_vector.h"

namespace s21 {

template <class T, class Container = s21::vector<T>>
class stack {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();
  stack &operator=(stack &&s);

  const_reference top();
  bool empty();
  size_type size();
  void push(const_reference value);
  void pop();
  void swap(stack &other);

 private:
  Container cont;
};

}  // namespace s21

#include "stack.tpp"
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_S21_STACK_H_
