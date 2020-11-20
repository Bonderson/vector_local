//
//  logic.cpp
//  Vector_1.0
//
//  Created by Bogdan Bochkarev on 11/11/20.
//  Copyright © 2020 Bogdan Bochkarev. All rights reserved.
//

#include "logic.hpp"

void vector::reserve(int newalloc) {
    if (newalloc <= space) return;
    double *p = new double[newalloc];
    for (int i=0; i<sz; ++i) p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

vector::vector(): sz{0}, elem{nullptr}, space{0} {} // das ergibt noch keinen Sinn, aber wir lassen das bis dann

vector::vector(int s): sz{s}, elem{new double[sz]}, space{sz} {
    for (int i=0; i<s; ++i) elem[i] = 0;
}

vector::vector(std::initializer_list<double> lst):
sz{static_cast<int>(lst.size())}, elem{new double[sz]}, space{sz} {
    std::copy(lst.begin(), lst.end(), elem);
}

vector::vector(const vector& arg): sz{arg.sz}, elem{new double[arg.sz]}, space{sz} {
    std::copy(arg.elem, arg.elem+sz, elem);
}

vector::vector(vector&& a): sz{a.sz}, elem{a.elem}, space{sz} {
    a.sz = 0; a.elem = nullptr; a.space = a.sz;
}

vector& vector::operator=(vector&& a) {
    delete[] elem;
    elem = a.elem; sz = a.sz;
    a.sz = 0; a.elem = nullptr;
    return *this;
}

vector& vector::operator=(const vector& a) {
    if (&a == this) return *this;
    if (a.sz <= space) {
        for (int i = 0; i<a.sz; ++i) elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }
    double* p = new double[a.sz];
    for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];
    delete[] elem; elem = p; space = sz = a.sz;
    return *this;
}

double& vector::operator[](int n) {
    return elem[n];
}

double vector::operator[](int n) const {
    return elem[n];
}

int vector::size() const {
    return sz;
}

double vector::get(int n) const {
    return elem[n];
}

void vector::set(int n, double v) {
    elem[n]=v;
}

void vector::resize(int newsize) {
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) elem[i] = 0;
    sz = newsize;
}

void vector::push_back(double d) {
    if (!space) reserve(8);
    else if (sz == space) reserve(2*space);
    elem[sz] = d;
    ++sz;
}

int vector::capacity() const {
    return space;
}

vector::~vector() {
    delete[] elem;
}
