#ifndef SRC_S21_CONTAINERSPLUS_H_ARRAY_TPP_
#define SRC_S21_CONTAINERSPLUS_H_ARRAY_TPP_

namespace s21 {

template<typename T, std::size_t Size>
array<T, Size>::array() {}

template<typename T, std::size_t Size>
array<T, Size>::array(std::initializer_list<value_type> const &items) {
    iterator it = items.begin();
    for(size_t n : it)
        elems[n] = *it;
}

template<typename T, std::size_t Size>
array<T, Size>::array(const array &other) {
    elems = other.elems;
}

template<typename T, std::size_t Size>
array<T, Size>::array(array &&other) {
    elems = std::move(other.elems);
}

template<typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::begin() {
    if (Size == 0)
        return nullptr;
    iterator it = elems[0];
    return it;
}

template<typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::end() {
    if (Size == 0)
        return nullptr;
    iterator it = elems[Size - 1];
    return it;
}

template<typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::data() {
    return begin();
}

template<typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::at(size_type pos) {
    return this[pos];
}

template<typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::front() {
    const_reference ref = elems[0];
    return ref;
}

template<typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::back() {
    const_reference ref = elems[Size - 1];
    return ref;
}

template<typename T, std::size_t Size>
bool array<T, Size>::empty() {
    for (int i : elems) {
        if (elems[i] != 0)
            return false;
    }
    return true;
}

template<typename T, std::size_t Size>
typename array<T, Size>::size_type array<T, Size>::size() {
    int ret = 0;
    for (int i : elems) {
        if (elems[i] != 0)
            ++ret;
    }
    return ret;
}

template<typename T, std::size_t Size>
typename array<T, Size>::size_type array<T, Size>::max_size() {
    return Size;
}

template<typename T, std::size_t Size>
void array<T, Size>::swap(array& other) {
    for (int i : other) {
        std::swap(elems[i], other.elems[i]);
    }
}

template<typename T, std::size_t Size>
void array<T, Size>::fill(const_reference value) {
    for (int i : elems) {
        elems[i] = value;
    }
}

template<typename T, std::size_t Size>
typename array<T, Size>::array& array<T, Size>::operator=(const array &other) {
    for (int i : other) {
        elems[i] = other.elems[i];
    }

    return *this;
}

template<typename T, std::size_t Size>
typename array<T, Size>::array& array<T, Size>::operator=(array &&other) {
    for (int i : other) {
        elems[i] = std::move(other.elems[i]);
    }

    return *this;
}

template<typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::operator[](size_type pos) {
    if (pos > Size - 1)
        return nullptr;
    return elems[pos];
}

}  // namespace s21

#endif  // SRC_S21_CONTAINERSPLUS_H_ARRAY_TPP_
