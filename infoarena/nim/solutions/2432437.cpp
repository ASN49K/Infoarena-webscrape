#include <bits/stdc++.h>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

void solve()
{
    int n;
    in >> n;

    int xor_sum = 0;

    for(int i = 1, x; i <= n; i++)
    {
        in >> x;
        xor_sum ^= x;
    }

    out << (xor_sum == 0 ? "NU\n" : "DA\n");
}

main()
{
    int t;
    in >> t;

    while(t--)
    {
        solve();
    }
}
