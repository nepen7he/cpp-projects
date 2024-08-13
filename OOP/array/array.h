#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

class ArrayOutOfRange : public std::out_of_range {
public:
    ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
    }
};

template <class T, size_t N>
class Array {
public:
    T array[N];
    T const& operator[](size_t index) const;
    T& operator[](size_t index);
    T const& At(size_t index) const;
    T& At(size_t index);
    T const& Front() const;
    T& Front();
    T const& Back() const;
    T& Back();
    T const* Data() const;
    T* Data();
    size_t Size() const;
    bool Empty() const;
    void Fill(const T& value);
    void Swap(Array<T, N>& other);
};

template <class T, size_t N>
bool operator==(const Array<T, N>& first, const Array<T, N>& second);
template <class T, size_t N>
bool operator!=(const Array<T, N>& first, const Array<T, N>& second);
template <class T, size_t N>
bool operator<(const Array<T, N>& first, const Array<T, N>& second);
template <class T, size_t N>
bool operator<=(const Array<T, N>& first, const Array<T, N>& second);
template <class T, size_t N>
bool operator>(const Array<T, N>& first, const Array<T, N>& second);
template <class T, size_t N>
bool operator>=(const Array<T, N>& first, const Array<T, N>& second);

#endif  // ARRAY_ARRAY_H

