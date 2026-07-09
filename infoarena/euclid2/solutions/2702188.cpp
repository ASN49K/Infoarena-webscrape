#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main (){
    int t;
    fin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b;
        fout << gcd(a, b);
    }
    return 0;
}
