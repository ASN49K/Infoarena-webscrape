#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b;

int cmmdc (int a, int b) {
    if (b) {
        cmmdc (b, a%b);
    }
    else {
        return a;
    }
}

int main () {
    fin >> t;
    for (int i = 1; i  <= t; ++i) {
        fin >> a >> b;
        fout << cmmdc(a, b);
    }
}
