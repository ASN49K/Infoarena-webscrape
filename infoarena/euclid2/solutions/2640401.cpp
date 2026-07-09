#include <bits/stdc++.h>
#define ll long long
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
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
    int n, x, y;
    fin >> n;
    while(n--) {
        fin >> x >> y;
        fout << gcd(x, y) << '\n';
    }

    return 0;
}
