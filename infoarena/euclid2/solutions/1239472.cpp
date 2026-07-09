//
//  main.cpp
//  euclid3
//
//  Created by Hai Tran Bach on 10/8/14.
//  Copyright (c) 2014 Hai Tran Bach. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

void gcd(int a, int b, int &x, int &y, int &temp) {
    
    if (!b) {
        x = 1;
        y = 0;
        temp = a;
    }
    else {
        int x1, y1;
        gcd(b, a % b, x, y, temp);
        x1=x;
        y1=y;
        y = x - (a / b) * (x = y);
        x1=x;
        y1=y;
    }
}

int main() {
    
    ifstream in("euclid3.in");
    ofstream out("euclid3.out");
    
    int nr = 0, a = 0, b = 0, c = 0, x = 0, y = 0, temp = 0;
    
    in >> nr;
    
    for (int i = 0; i < nr; ++i) {
        in >> a >> b >> c;
        gcd(a, b, x, y, temp);
        if (c % temp == 0) {
            out << x * c / temp  << " " << y * c / temp << "\n";
        }
        else {
            out << "0 0 \n";
        }
    }
    
    return 0;
}
