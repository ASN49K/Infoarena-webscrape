#include <bits/stdc++.h>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int n, x, y;

int euclid(int a, int b)
{
    int r=a%b;
    while (r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    in >> n;
    for (int i=1; i<=n; i++)
    {
        in >> x >> y;
        out << euclid(x,y) << '\n';
    }
    return 0;
}
