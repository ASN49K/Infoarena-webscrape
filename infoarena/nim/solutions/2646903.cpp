#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

void usain_bolt()
{
    ios::sync_with_stdio(false);
    fin.tie(0);
}

const int N = 1e4 + 5;

int a[N];

int main()
{
    usain_bolt();

    int tt;

    fin >> tt;
    for(; tt; --tt) {
        int n;

        fin >> n;
        int xorr = 0;
        for(int i = 1; i <= n; ++i) fin >> a[i], xorr ^= a[i];
        fout << ((xorr > 0) ? "DA\n" : "NU\n");
    }
    return 0;
}
