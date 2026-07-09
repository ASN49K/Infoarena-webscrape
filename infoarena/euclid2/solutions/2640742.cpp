#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
    if(b < a)
        swap(b, a);
    while(a != 0) {
        int rest = b % a;
        b = a;
        a = rest;
    }
    return b;
}

int main() {
    int n;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
}
