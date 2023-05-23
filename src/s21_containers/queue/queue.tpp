#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_QUEUE_QUEUE_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_QUEUE_QUEUE_TPP_

namespace s21 {

template <typename T, typename Container>
queue<T, Container>::queue() : cont() {}

template <typename T, typename Container>
queue<T, Container>::queue(std::initializer_list<value_type> const &items)
    : cont(items) {}

template <typename T, typename Container>
queue<T, Container>::queue(const queue &s) : cont(s.cont) {}

template <typename T, typename Container>
queue<T, Container>::queue(queue &&s) : cont(std::move(s.cont)) {}

template <typename T, typename Container>
queue<T, Container>::~queue() {}

template <typename T, typename Container>
typename queue<T, Container>::queue &queue<T, Container>::operator=(queue &&s) {
  this->cont = std::move(s.cont);
  return *this;
}

template <typename T, typename Container>
typename queue<T, Container>::const_reference queue<T, Container>::front() {
  return cont.front();
}

template <typename T, typename Container>
typename queue<T, Container>::const_reference queue<T, Container>::back() {
  return cont.back();
}

template <typename T, typename Container>
bool queue<T, Container>::empty() {
  return cont.empty();
}

template <typename T, typename Container>
typename queue<T, Container>::size_type queue<T, Container>::size() {
  return cont.size();
}

template <typename T, typename Container>
void queue<T, Container>::push(const_reference value) {
  this->cont.push_back(value);
}

template <typename T, typename Container>
void queue<T, Container>::pop() {
  this->cont.pop_front();
}

template <typename T, typename Container>
void queue<T, Container>::swap(queue &other) {
  this->cont.swap(other.cont);
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_QUEUE_QUEUE_TPP_