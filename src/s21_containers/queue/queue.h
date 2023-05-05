#ifndef SRC_S21_CONTAINERS_H_QUEUE_QUEUE_H_
#define SRC_S21_CONTAINERS_H_QUEUE_QUEUE_H_

#include "../list/list.h"

namespace s21 {

template <typename T, typename Container = s21::List<T>>
class Queue {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  Queue();
  Queue(std::initializer_list<value_type> const &items);
  Queue(const Queue &s);
  Queue(Queue &&s);
  ~Queue();
  Queue &operator=(Queue &&s);

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(Queue &other);

 private:
  Container cont;
};

}  // namespace s21

#include "queue.tpp"

#endif  // SRC_S21_CONTAINERS_H_QUEUE_QUEUE_H_
