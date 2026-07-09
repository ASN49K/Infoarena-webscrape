#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, x;

int main() {
    fin >> t;
    for (int i = 0; i < t; i++) {
        fin >> n;
        int s;
        fin >> s;
        for (int i = 1; i < n; i++) {
            fin >> x;
            s ^= x;
        }
        fout << (s ? "DA\n" : "NU\n");
    }
}