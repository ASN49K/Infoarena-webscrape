#include <bits/stdc++.h>
#define ll long long
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, v[17];

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);

    while (b != 0) {
        int rest = a % b;
        a = b;
        b = rest;
    }

    return a;
}

int main() {
    int n, x, y;

    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> x >> y;
        fout << gcd(x, y) << "\n";
    }

    return 0;
}