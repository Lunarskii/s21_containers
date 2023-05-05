#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_TPP_

namespace s21 {

template <class T, class Container>
Stack<T, Container>::Stack() : cont() {}

template <class T, class Container>
Stack<T, Container>::Stack(std::initializer_list<value_type> const &items)
    : cont(items) {}

template <class T, class Container>
Stack<T, Container>::Stack(const Stack &s) : cont(s.cont) {}

template <class T, class Container>
Stack<T, Container>::Stack(Stack &&s) : cont(std::move(s.cont)) {}

template <class T, class Container>
Stack<T, Container>::~Stack() {}

template <class T, class Container>
Stack<T, Container> &Stack<T, Container>::operator=(Stack &&s) {
  this->cont = std::move(s.cont);
  return *this;
}

template <class T, class Container>
typename Stack<T, Container>::const_reference Stack<T, Container>::top() {
  return cont.back();
}

template <class T, class Container>
bool Stack<T, Container>::empty() {
  return cont.empty();
}

template <class T, class Container>
typename Stack<T, Container>::size_type Stack<T, Container>::size() {
  return cont.size();
}

template <class T, class Container>
void Stack<T, Container>::push(const_reference value) {
  this->cont.push_back(value);
}

template <class T, class Container>
void Stack<T, Container>::pop() {
  this->cont.pop_back();
}

template <class T, class Container>
void Stack<T, Container>::swap(Stack &other) {
  this->cont.swap(other.cont);
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_TPP_