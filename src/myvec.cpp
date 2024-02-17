#include <myvec.h>

using namespace myvec;

#include <cstdlib>
#include <cstring>

MyVector::MyVector() {
    ptr = 0;
    _size = capacity = 0;
}

MyVector::~MyVector() {
    if (ptr) free(ptr);
}

void MyVector::push_back(int value) {
    if (capacity <= _size) {
        if (capacity) capacity <<= 1;
        else capacity = 1;
        ptr = (int*)realloc(ptr, capacity * sizeof(int));
    }
    ptr[_size++] = value;
}

void MyVector::pop_back() {
    _size--;
}

void MyVector::clear() {
    _size = 0;
}

void MyVector::resize(unsigned int n) {
    if (n == _size) return;
    if (n < _size) {
        _size = n;
        return;
    }
    if (capacity <= n) {
        while (capacity <= n) capacity <<= 1;
        ptr = (int*)realloc(ptr, capacity * sizeof(int));
    }
    memset(ptr + _size, 0, (n - _size) * sizeof(int));
    _size = n;
}

unsigned int MyVector::size() {
    return _size;
}

bool MyVector::empty() {
    return _size == 0;
}

int MyVector::get(int i) {
    if (i < 0 || i >= (int)_size) return 0;
    return ptr[i];
}
