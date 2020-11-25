//
//  logic.hpp
//  Vector_1.0
//
//  Created by Bogdan Bochkarev on 11/11/20.
//  Copyright © 2020 Bogdan Bochkarev. All rights reserved.
//

#ifndef logic_hpp
#define logic_hpp

#include <stdio.h>
#include <initializer_list>
#include <algorithm>


template<class T> class vector {
private:
    int sz; // Размер
    T* elem; // Ука за тель на первый элемент puЬlic: (типа douЬl e)
    int space;
    
    void reserve(int);

public:
    vector();
    explicit vector(int);
    vector(std::initializer_list<T>);
    vector(const vector&);
    vector(vector&&);
    
    
    vector& operator=(vector&&);
    vector& operator=(const vector&);
    
    T& operator[](int);
    T operator[](int) const;
    
    
    int size() const; // Текущий размер
    T get(int) const;
    void set(int, T);
    void resize(int);
    void push_back(T);
    int capacity() const;
    
    
    ~vector();
};


#endif /* logic_hpp */
