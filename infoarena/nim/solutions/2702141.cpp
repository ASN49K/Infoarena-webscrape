#include <bits/stdc++.h>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
void solve()
{
    int n, s = 0;
    f >> n;
    for (int x; n; n--)
        f >> x, s ^= x;
    g << (s ? "DA\n" : "NU\n");
}
int main()
{
    int q;
    for (f >> q; q; q--)
        solve();
    return 0;
}
