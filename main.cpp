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
    vector<double> v1(5) ;
    vector<double> v2 = {5.0};
    vector<double> v3 = v2;
//    vector<std::string> vs(6);
//    vs[0] = "abc";
//    vs.set(5, "Norah");
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
//    for (int i=0; i<vs.size(); ++i) {
//        std::cout << "v[" << i << "]==" << vs[i] << std::endl;
//    }
    return 0;
}
