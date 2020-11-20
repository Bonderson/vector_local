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


class vector {
private:
    int sz; // Размер
    double* elem; // Ука за тель на первый элемент puЬlic: (типа douЬl e)
    int space;
    
    void reserve(int);

public:
    vector();
    explicit vector(int);
    vector(std::initializer_list<double>);
    vector(const vector&);
    vector(vector&&);
    
    
    vector& operator=(vector&&);
    vector& operator=(const vector&);
    
    double& operator[](int);
    double operator[](int) const;
    
    
    int size() const; // Текущий размер
    double get(int) const;
    void set(int, double);
    void resize(int);
    void push_back(double);
    int capacity() const;
    
    
    ~vector();
};


#endif /* logic_hpp */
