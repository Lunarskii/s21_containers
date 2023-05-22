#ifndef SRC_S21_CONTAINERSPLUS_H_ARRAY_H_
#define SRC_S21_CONTAINERSPLUS_H_ARRAY_H_

namespace s21 {
template<typename T, typename std::size_t Size>
class array {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;
    using size_type = size_t;

    array();
    array(std::initializer_list<value_type> const &items);
    array(const array &other);
    array(array &&other);
    ~array() = default;

    iterator begin();
    iterator end();
    iterator data();

    reference  at(size_type pos);
    const_reference front();
    const_reference back();

    bool empty();
    size_type size();
    size_type max_size();

    void swap(array& other);
    void fill(const_reference value);

    array& operator=(const array &other);
    array& operator=(array &&other);
    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

private:
    value_type elems[Size] = {};
    size_type capacity = Size;
};

}  // namespace s21

#include "array.tpp"

#endif  // SRC_S21_CONTAINERSPLUS_H_ARRAY_H_
