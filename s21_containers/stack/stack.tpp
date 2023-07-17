#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_TPP_

namespace s21 {

template <class T, class Container>
stack<T, Container>::stack() : cont() {}

template <class T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const &items)
    : cont(items) {}

template <class T, class Container>
stack<T, Container>::stack(const stack &s) : cont(s.cont) {}

template <class T, class Container>
stack<T, Container>::stack(stack &&s) : cont(std::move(s.cont)) {}

template <class T, class Container>
stack<T, Container>::~stack() {}

template <class T, class Container>
stack<T, Container> &stack<T, Container>::operator=(stack &&s) {
  this->cont = std::move(s.cont);
  return *this;
}

template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() {
  return cont.back();
}

template <class T, class Container>
bool stack<T, Container>::empty() {
  return cont.empty();
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() {
  return cont.size();
}

template <class T, class Container>
void stack<T, Container>::push(const_reference value) {
  this->cont.push_back(value);
}

template <class T, class Container>
void stack<T, Container>::pop() {
  this->cont.pop_back();
}

template <class T, class Container>
void stack<T, Container>::swap(stack &other) {
  this->cont.swap(other.cont);
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_TPP_