#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,x,y,r;
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>x>>y;
        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        g<<x<<'\n';
    }
    return 0;
}
