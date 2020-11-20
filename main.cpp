//
//  main.cpp
//  Vector_1.0
//
//  Created by Bogdan Bochkarev on 11/11/20.
//  Copyright © 2020 Bogdan Bochkarev. All rights reserved.
//

#include <iostream>
#include "logic.hpp"

int main(int argc, const char * argv[]) {
    vector v1(5) ;
    vector v2 = {5.0};
    vector v3 = v2;
    std::cout << v3.get(0) << std::endl;
    v3.set(0, 4.0);
    for (int i=0; i<v1.size(); ++i) {
        v1.set(i,1.1*i);
        std::cout << "v[" << i << "]==" << v1.get(i) << std::endl;
    }
    for (int i=0; i<v2.size(); ++i) {
        std::cout << "v[" << i << "]==" << v2.get(i) << std::endl;
    }
    for (int i=0; i<v3.size(); ++i) {
        std::cout << "v[" << i << "]==" << v3.get(i) << std::endl;
    }
    return 0;
}
