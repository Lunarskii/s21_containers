#ifndef STACK_H
#define STACK_H

#include "../vector/s21_vector.h"

namespace s21 {

template <class T, class Container = s21::vector<T>>
class Stack {
 public:
  using pointer = typename Container::pointer;
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  Stack();
  Stack(std::initializer_list<value_type> const &items);
  Stack(const Stack &s);
  Stack(Stack &&s);
  ~Stack();
  Stack &operator=(Stack &&s);

  const_reference top();
  bool empty();
  size_type size();
  void push(const_reference value);
  void pop();
  void swap(Stack &other);

 private:
  Container cont;
};

}  // namespace s21

#include "stack.tpp"
#endif  // STACK_H
