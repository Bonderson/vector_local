//
//  logic.cpp
//  Vector_1.0
//
//  Created by Bogdan Bochkarev on 11/11/20.
//  Copyright © 2020 Bogdan Bochkarev. All rights reserved.
//

#include "logic.hpp"

template<typename T> void vector<T>::reserve(int newalloc) {
    if (newalloc <= space) return;
    T* p = new T[newalloc];
    for (int i=0; i<sz; ++i) p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

template<typename T> vector<T>::vector(): sz{0}, elem{nullptr}, space{0} {} // das ergibt noch keinen Sinn, aber wir lassen das bis dann

template<typename T> vector<T>::vector(int s): sz{s}, elem{new T[sz]}, space{sz} {
    for (int i=0; i<s; ++i) elem[i] = 0;
}

template<typename T> vector<T>::vector(std::initializer_list<T> lst):
sz{static_cast<int>(lst.size())}, elem{new T[sz]}, space{sz} {
    std::copy(lst.begin(), lst.end(), elem);
}

template<typename T> vector<T>::vector(const vector<T>& arg): sz{arg.sz}, elem{new T[arg.sz]}, space{sz} {
    std::copy(arg.elem, arg.elem+sz, elem);
}

template<typename T> vector<T>::vector(vector<T>&& a): sz{a.sz}, elem{a.elem}, space{sz} {
    a.sz = 0; a.elem = nullptr; a.space = a.sz;
}

template<typename T> vector<T>& vector<T>::operator=(vector<T>&& a) {
    delete[] elem;
    elem = a.elem; sz = a.sz;
    a.sz = 0; a.elem = nullptr;
    return *this;
}

template<typename T> vector<T>& vector<T>::operator=(const vector<T>& a) {
    if (&a == this) return *this;
    if (a.sz <= space) {
        for (int i = 0; i<a.sz; ++i) elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }
    T* p = new T[a.sz];
    for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];
    delete[] elem; elem = p; space = sz = a.sz;
    return *this;
}

template<typename T> T& vector<T>::operator[](int n) {
    if (0 <= n && n <= sz) return elem[n];
    throw std::runtime_error("Out of range.\n");
}

template<typename T> T vector<T>::operator[](int n) const {
    if (0 <= n && n <= sz) return elem[n];
    throw std::runtime_error("Out of range.\n");
}

template<typename T> int vector<T>::size() const {
    return sz;
}

template<typename T> T vector<T>::get(int n) const {
    return elem[n];
}

template<typename T> void vector<T>::set(int n, T t) {
    elem[n]=t;
}

template<typename T> void vector<T>::resize(int newsize) {
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) elem[i] = 0;
    sz = newsize;
}

template<typename T> void vector<T>::push_back(T t) {
    if (!space) reserve(8);
    else if (sz == space) reserve(2*space);
    elem[sz] = t;
    ++sz;
}

template<typename T> int vector<T>::capacity() const {
    return space;
}

template<typename T> vector<T>::~vector() {
    delete[] elem;
}
