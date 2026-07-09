//
//  main.cpp
//  euclid2
//
//  Created by Hai Tran Bach on 10/8/14.
//  Copyright (c) 2014 Hai Tran Bach. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

long cmmdc(long a, long b) {
    do {
        if (a > b) {
            swap(a, b);
        }
        b = b % a;
    } while (b > 0);
    return a;
    
}

int main() {
    long a = 0, b = 0;
    int t = 0;
    
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in >> t;
    
    for (int i = 0; i < t; ++i) {
        in >> a >> b;
        out << cmmdc(a, b) << endl;
    }
        
    return 0;
}
