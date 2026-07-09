#include <bits/stdc++.h>

using namespace std;

int cmmdc(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    while (b > 0) {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main() {
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int t;
    fin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}