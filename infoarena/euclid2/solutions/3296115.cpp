#include <bits/stdc++.h>
#define NMAX 100

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b;

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    fin >> t;
    while (t--) {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }
    return 0;
}
