#include <bits/stdc++.h>

using namespace std;

ifstream in ("nim.in");
ofstream out ("nim.out");

const int NMAX = 1e4;

static inline void solve()
{
    int n;
    in >> n;
    int XOR = 0;
    for (int i=0; i<n; i++)
    {
        int x;
        in >> x;
        XOR ^= x;
    }
    if (!XOR)
        out << "NU\n";
    else
        out << "DA\n";
}

int main()
{
    int tc;
    in >> tc;
    while (tc--)
        solve();
    return 0;
}
