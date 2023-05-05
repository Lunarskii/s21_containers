#ifndef SRC_S21_CONTAINERS_H_QUEUE_QUEUE_TPP_
#define SRC_S21_CONTAINERS_H_QUEUE_QUEUE_TPP_

namespace s21 {

template <typename T, typename Container>
Queue<T, Container>::Queue() : cont() {}

template <typename T, typename Container>
Queue<T, Container>::Queue(std::initializer_list<value_type> const &items)
    : cont(items) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(const Queue &s) : cont(s.cont) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(Queue &&s) : cont(std::move(s.cont)) {}

template <typename T, typename Container>
Queue<T, Container>::~Queue() {}

template <typename T, typename Container>
typename Queue<T, Container>::Queue &Queue<T, Container>::operator=(Queue &&s) {
  this->cont = std::move(s.cont);
  return *this;
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::front() {
  return cont.front();
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::back() {
  return cont.back();
}

template <typename T, typename Container>
bool Queue<T, Container>::empty() {
  return cont.empty();
}

template <typename T, typename Container>
typename Queue<T, Container>::size_type Queue<T, Container>::size() {
  return cont.size();
}

template <typename T, typename Container>
void Queue<T, Container>::push(const_reference value) {
  this->cont.push_back(value);
}

template <typename T, typename Container>
void Queue<T, Container>::pop() {
  this->cont.pop_front();
}

template <typename T, typename Container>
void Queue<T, Container>::swap(Queue &other) {
  this->cont.swap(other.cont);
}

}  // namespace s21
#endif  // SRC_S21_CONTAINERS_H_QUEUE_QUEUE_H_