#include "array.h"
#include <iostream>
#include <iterator>
#include <stdexcept>

template <class T, size_t N>
T const& Array<T, N>::operator[](size_t index) const {
    if (index >= N) {
        throw ArrayOutOfRange{};
    }
    return array[index];
}

template <class T, size_t N>
T& Array<T, N>::operator[](size_t index) {
    if (index >= N) {
        throw ArrayOutOfRange{};
    }
    return array[index];
}

template <class T, size_t N>
T const& Array<T, N>::At(size_t index) const {
    if (index >= N) {
        throw ArrayOutOfRange{};
    }
    return array[index];
}

template <class T, size_t N>
T& Array<T, N>::At(size_t index) {
    if (index >= N) {
        throw ArrayOutOfRange{};
    }
    return array[index];
}

template <class T, size_t N>
T const& Array<T, N>::Front() const {
    if (N == 0) {
        throw ArrayOutOfRange{};
    }
    return array[0];
}

template <class T, size_t N>
T& Array<T, N>::Front() {
    if (N == 0) {
        throw ArrayOutOfRange{};
    }
    return array[0];
}

template <class T, size_t N>
T const& Array<T, N>::Back() const {
    if (N == 0) {
        throw ArrayOutOfRange{};
    }
    return array[N - 1];
}

template <class T, size_t N>
T& Array<T, N>::Back() {
    if (N == 0) {
        throw ArrayOutOfRange{};
    }
    return array[N - 1];
}

template <class T, size_t N>
T const* Array<T, N>::Data() const {
    return &(array[0]);
}

template <class T, size_t N>
T* Array<T, N>::Data() {
    return &(array[0]);
}

template <class T, size_t N>
size_t Array<T, N>::Size() const {
    return N;
}

template <class T, size_t N>
bool Array<T, N>::Empty() const {
    return N == 0;
}

template <class T, size_t N>
void Array<T, N>::Fill(const T& value) {
    for (size_t i = 0; i < N; ++i) {
        array[i] = value;
    }
}

template <class T, size_t N>
void Array<T, N>::Swap(Array<T, N>& other) {
    T temp;
    for (size_t i = 0; i < N; ++i) {
        temp = array[i];
        array[i] = other[i];
        other[i] = temp;
    }
}

namespace std {
template <class T, size_t N>
void swap(Array<T, N>& first, Array<T, N>& second) {  // NOLINT
    first.Swap(second);
}
}  // namespace std

template <class T, size_t N>
bool operator==(const Array<T, N>& first, const Array<T, N>& second) {
    bool is_equal = true;
    for (size_t i = 0; i < N; ++i) {
        if (first[i] != second[i]) {
            is_equal = false;
            break;
        }
    }
    return is_equal;
}

template <class T, size_t N>
bool operator!=(const Array<T, N>& first, const Array<T, N>& second) {
    return !(first == second);
}

template <class T, size_t N>
bool operator<(const Array<T, N>& first, const Array<T, N>& second) {
    bool is_less = false;
    for (size_t i = 0; i < N; ++i) {
        if (first[i] != second[i]) {
            is_less = first[i] < second[i];
            break;
        }
    }
    return is_less;
}

template <class T, size_t N>
bool operator<=(const Array<T, N>& first, const Array<T, N>& second) {
    return first == second || first < second;
}

template <class T, size_t N>
bool operator>(const Array<T, N>& first, const Array<T, N>& second) {
    return !(first <= second);
}

template <class T, size_t N>
bool operator>=(const Array<T, N>& first, const Array<T, N>& second) {
    return first == second || first > second;
}
