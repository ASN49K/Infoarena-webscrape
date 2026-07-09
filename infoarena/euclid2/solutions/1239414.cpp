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

int gcd(int a, int b) {
    
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
    
}

int main() {
    int t = 0, a = 0, b = 0;
    
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in >> t;
    
    for (int i = 0; i < t; ++i) {
        in >> a >> b;
        out << gcd(a, b) << endl;
    }
        
    return 0;
}
