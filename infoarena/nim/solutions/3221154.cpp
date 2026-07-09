#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const char sp = ' ';
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const char out[2][4]{ "NO", "YES" };
#define all(a) a.begin(), a.end()
using ll = long long;
ifstream fin("nim.in");
ofstream fout("nim.out");

const int nmax = 1e4;
int n;
int a[nmax + 5]{ 0 };

void testcase() {
    fin >> n;
    int x = 0;
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
        x ^= a[i];
    }
    fout << (x ? "DA" : "NU") << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    fin >> tc;
    for (int t = 1; t <= tc; ++t) {
#ifdef _DEBUG
        cerr << "=== Subtask " << t << " ===" << nl;
#endif
        testcase();
#ifdef _DEBUG
        cerr << nl;
#endif
    }
}