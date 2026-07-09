#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    fin >> tt;

    while(tt--) {
        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }

    return 0;
}
