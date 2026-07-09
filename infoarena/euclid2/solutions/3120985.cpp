#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gdc(int n, int m) {
    while (m != 0) {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main() {
    int t;
    fin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b;
        fin >> a >> b;
        fout << gdc(a, b) << '\n';
    }
    return 0;
}
