#include <stdexcept>
template<typename T>

class vector {

private:
    size_t _size;           // number of elements
    size_t _capacity;       // current capacity of container
    T* _data;

    void resize();          // need more space
public:
    using iterator = T*;

    vector();
    ~vector();

    size_t size() const;    // Const means this function doesn't modify object,
                            // by doing so we can use it when we passing v as const.
                            // Remember we also need to add const to the implementation
    bool empty() const;

    T& operator[] (size_t index);
    const T& at(size_t index) const;// 1st for return value, 2nd for function
    T& at(size_t index);    // const overloading, otherwise we cannot update vec

    void push_back(const T& elem);

    iterator begin();
    iterator end();
};

/* #include "vector.cpp" */
template <typename T>
vector<T>::vector() {
    _size = 0;
    _capacity = 4;
    _data = new T[_capacity];
}

template<typename T>
vector<T>::~vector() {
    delete[] _data;
}

template <typename T>
void vector<T>::resize() {
    auto newData = new T[_capacity * 2];
    for (size_t i = 0; i < _size; i++) {        // move elements to newData
        newData[i] = _data[i];
    }
    
    delete[] _data;
    _capacity *= 2;
    _data = newData;
}

template<typename T>
size_t vector<T>::size() const {
    return _size;
}

template<typename T>
bool vector<T>::empty() const {
    return _size == 0;
}

template<typename T>
T& vector<T>::operator[](size_t index) {
    return _data[index];
}

template<typename T>
const T& vector<T>::at(size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Out of range!");
    }
    return _data[index];
}

template<typename T>
T& vector<T>::at(size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Out of range!");
    }
    return _data[index];
}

template<typename T>
void vector<T>::push_back(const T& elem) {
    if (_size == _capacity) {
        resize();
    }
    _data[_size++] = elem;
}

template<typename T>
vector<T>::iterator vector<T>::begin() {
    return _data;
}

template<typename T>
vector<T>::iterator vector<T>::end() {
    return _data + _size;
}
