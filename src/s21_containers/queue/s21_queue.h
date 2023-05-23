#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_QUEUE_S21_QUEUE_H_

#include "../list/s21_list.h"

namespace s21 {

template <typename T, typename Container = s21::list<T>>
class queue {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &s);
  queue(queue &&s);
  ~queue();
  queue &operator=(queue &&s);

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(queue &other);

 private:
  Container cont;
};

}  // namespace s21

#include "queue.tpp"

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_QUEUE_S21_QUEUE_H_
