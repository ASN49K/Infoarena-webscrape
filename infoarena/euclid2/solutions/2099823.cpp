#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int t,n,m,a,b;
    f>>t;
    for (int i=1;i<=t;++i)
    {
        f>>n>>m;
        a=n ; b=m;
        int r;
        while (b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        if (i!=t) g<<a<<'\n';
    }
    g<<a;
    return 0;
}
