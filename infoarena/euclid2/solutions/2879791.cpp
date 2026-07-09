#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b) {
    int aux;
    while(b) {
        aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}

int main() {
    int t;
    f >> t;
    for(int i = 0; i < t; i++) {
        int a, b;
        f >> a >> b;
        g << cmmdc(a, b) << '\n';
    }
    return 0;
}