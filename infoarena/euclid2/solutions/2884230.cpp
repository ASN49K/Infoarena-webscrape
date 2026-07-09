#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int t;
    fin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        fin >> n >> m;
        while (m) {
            int r = n % m;
            n = m;
            m = r;
        }
        fout << n << '\n';
    }
    return 0;
}
