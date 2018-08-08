//
//  main.cpp
//  vectPract2
//
//  Created by Kyra Thompson on 8/3/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

class vect{
    int sz;
    double* elem;
public:
    vect(int s) : sz{s}, elem{new double[s]} {}
    vect(const vect& arg) : sz{arg.sz}, elem{new double[arg.sz]}
    {
        copy(arg.elem, arg.elem + arg.sz, elem);
    }
    vect& operator=(const vect& a){
        double* p = new double[a.sz];
        copy(a.elem, a.elem + a.sz, p);
        delete[] elem;
        elem = p;
        sz = a.sz;
        return *this;
    }
    double& operator[](int n) { return elem[n]; }
    double operator[](int n) const { return elem[n]; }
    
    ~vect() {delete[] elem;}
   
//    double get(int i){ return elem[i]; }
//    void set(int i, double d){
//        elem[i] = d;
//    }
};
void f (int n){
    vect v(3);
    v[2] = 2.2;
    vect v2 = v;

    v[1] = 9.9;
    v2[0] = 8.8;
    cout << v[0] << ' ' << v2[1] << endl;
//    vect v(3);
//    v.set(2,2.2);
//    vect v2 = v;
//    v.set(1,9.9);
//    v2.set(0, 8.8);
//    cout << v.get(0) << ' ' << v2.get(1);

}

int main() {
    int i = 0;
    while(i < 50){
        f(3);
        ++i;
    }
    return 0;
}
