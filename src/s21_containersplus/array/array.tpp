#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_ARRAY_ARRAY_TPP_
#define CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_ARRAY_ARRAY_TPP_

namespace s21 {

template<typename T, std::size_t Size>
array<T, Size>::array() {}

template<typename T, std::size_t Size>
array<T, Size>::array(std::initializer_list<value_type> const &items) {
    std::copy(items.begin(), items.end(), elems);
}

template<typename T, std::size_t Size>
array<T, Size>::array(const array &other) {
    for(size_t i : other.elems) {
        elems[i] = other.elems[i];
    }
}

template<typename T, std::size_t Size>
array<T, Size>::array(array &&other) {
    for(size_t i : other.elems) {
        elems[i] = std::move(other.elems[i]);
    }
}

template<typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::begin() {
    return elems;
}

template<typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::end() {
    return elems + capacity;
}

template<typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::data() {
    return begin();
}

template<typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::at(size_type pos) {
    return (*this)[pos];
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
    return !capacity;
}

template<typename T, std::size_t Size>
typename array<T, Size>::size_type array<T, Size>::size() {
    return capacity;
}

template<typename T, std::size_t Size>
typename array<T, Size>::size_type array<T, Size>::max_size() {
    return capacity;
}

template<typename T, std::size_t Size>
void array<T, Size>::swap(array& other) {
    T temp;
    for (size_t i = 0; i < capacity; ++i) {
        temp = elems[i];
        elems[i] = other.elems[i];
        other.elems[i] = temp;
    }
}

template<typename T, std::size_t Size>
void array<T, Size>::fill(const_reference value) {
    for (size_t i = 0; i < capacity; ++i) {
        elems[i] = value;
    }
}

template<typename T, std::size_t Size>
typename array<T, Size>::array& array<T, Size>::operator=(const array &other) {
    for (size_t i = 0; i < capacity; ++i) {
        elems[i] = other.elems[i];
    }

    return *this;
}

template<typename T, std::size_t Size>
typename array<T, Size>::array& array<T, Size>::operator=(array &&other) {
    for (size_t i = 0; i < capacity; ++i) {
        elems[i] = std::move(other.elems[i]);
    }

    return *this;
}

template<typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::operator[](size_type pos) {
    if (pos >= Size)
        throw std::out_of_range("s21:array operator[] - Index out of range");
    return elems[pos];
}

template<typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::operator[](size_type pos) const {
    if (pos >= Size)
        throw std::out_of_range("s21:array operator[] - Index out of range");
    return elems[pos];
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_ARRAY_ARRAY_TPP_