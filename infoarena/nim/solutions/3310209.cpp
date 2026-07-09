#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>

using namespace std;

#define NMAX 1000000
#define MMAX 4
#define PMAX 524288
#define LOG 8
#define INF 0x3f3f3f3f
#define BS 127
#define MOD 1000000007

#define ll long long
#define ull unsigned long long
#define ldb long double

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, x, sum;

void solve() {
    fin >> n;
    sum = 0;

    for (int i = 1; i <= n; i++) {
        fin >> x;
        sum ^= x;
    }

    fout << (sum ? "DA" : "NU") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    fin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
