#include <bits/stdc++.h>
#define ll long long
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b-a);
}

int main() {
    int t;
    fin >> t;
    while(t--) {
        int  a, b;
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }
    return 0;
}
