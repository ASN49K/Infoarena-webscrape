//
// Created by Radu Vrinceanu on 12.04.2021.
//

#ifndef OLIMPIADA_EUCLID2_H
#define OLIMPIADA_EUCLID2_H

#endif //OLIMPIADA_EUCLID2_H
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned int T;
unsigned int gcd(unsigned int a, unsigned int b) {
    unsigned int r = a % b;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    fin >> T;
    for (unsigned int i = 0, a, b; i < T; ++i) {
        fin >> a >> b;
        fout << gcd(a, b);
    }
    fin.close();
    fout.close();

    return 0;
}