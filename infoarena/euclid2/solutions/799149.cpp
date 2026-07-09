//
//  AlgoritmEuclid.cpp
//  Algoritmul lui Euclid
//
//  Created by Andrei Constantinescu on 10/18/12.
//  Copyright (c) 2012 Andrei Constantinescu. All rights reserved.
//

#include <fstream>
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int cmmdc (int x, int y) {
    int r;
    while (y) {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main() {
    int nr1, nr2, n, i;
    f>>n;
    for (i=1; i<=n; i++) {
        f>>nr1;
        f>>nr2;
        g<<cmmdc(nr1, nr2);
        g<<"\n";
    }
    f.close();
    g.close();
}

