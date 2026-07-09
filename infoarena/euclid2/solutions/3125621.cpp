#include <bits/stdc++.h>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int x, y, t;

int solve(int &x, int &y)
{
    while (y)
    {
        int r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main()
{
    f >> t;

    while (t--)
    {
        f >> x >> y;
        g << solve(x, y) << '\n';
    }
    return 0;
}
