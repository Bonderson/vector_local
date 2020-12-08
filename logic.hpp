//
//  logic.hpp
//  Vector_1.0
//
//  Created by Bogdan Bochkarev on 11/11/20.
//  Copyright © 2020 Bogdan Bochkarev. All rights reserved.
//

#ifndef logic_hpp
#define logic_hpp

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <initializer_list>
#include <algorithm>
#include <memory>
#include <string>

//template<typename T> class allocator {
//public:
//    T* allocate(int n);
//    void deallocate(T* p, int n);
//    void construct(T* p, const T& v);
//    void destroy(T* p);
//};

template<typename T, typename A = std::allocator<T>> class Vector {
private:
    A alloc;
    int sz; // Размер
    T* elem;
    int space;
    
    void reserve(int);

public:
    Vector();
    explicit Vector(int);
    Vector(std::initializer_list<T>);
    Vector(const Vector&);
    Vector(Vector&&);
    
    
    Vector& operator=(Vector&&);
    Vector& operator=(const Vector&);
    
    T& operator[](int);
    T operator[](int) const;
    
    
    int size() const; // Текущий размер
    T get(int) const;
    void set(int, T);
    void resize(int, T val=T());
    void push_back(const T&);
    int capacity() const;
    
    
    ~Vector();
};


#endif /* logic_hpp */
