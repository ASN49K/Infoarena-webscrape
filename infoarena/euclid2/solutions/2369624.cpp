#include <bits/stdc++.h>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int x,y,t;
int usu(int x,int y)
{
    int r=0;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    f>>t;
    while(t--)
    {
        f>>x>>y;
        g<<usu(x,y)<<'\n';
    }
    return 0;
}
