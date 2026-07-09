#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

ifstream in { "euclid2.in" };
ofstream out { "euclid2.out" };

int cmmdc(int a, int b) { return b == 0 ? a : cmmdc(b, a % b); }

int main() {
    int t; in >> t;
    
    while (t--) {
        int a, b; in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }
}
