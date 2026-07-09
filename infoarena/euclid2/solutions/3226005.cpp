#include <bits/stdc++.h>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int t;

int a,b;

void euclid(int a, int b)
{
    if(b == 0)
    {
        out << a << '\n';
    }
    else
    {
        euclid(b, a % b);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    in.tie(NULL);
    in >> t;
    while(t --)
    {
        in >> a >> b;
        if(a < b)
        {
            swap(a,b);
        }
        euclid(a,b);
    }
    return 0;
}
