#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int n, int m) {
    while (m) {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main() {
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        fout << cmmdc(x, y) << '\n';
    }
    return 0;
}
