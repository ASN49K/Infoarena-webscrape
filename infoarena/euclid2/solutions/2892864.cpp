#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int tests;
    fin >> tests;
    for (int i = 1; i <= tests; ++i) {
        int a, b;
        fin >> a >> b;
        fout << __gcd(a, b) << '\n';
    }
    return 0;
}
