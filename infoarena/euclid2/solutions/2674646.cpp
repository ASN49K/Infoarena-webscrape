#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid_extins(int a, int b, int &x, int &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }
    int x1,y1;
    int d = euclid_extins(b%a,a,x1,y1);
    x = y1-(b/a)*x1;
    y=x1;
    return d;
}
int main()
{
    int t;
    f>>t;
    for(int test=1;test<=t;test++)
    {
        int a,b,c;
        f>>a>>b;
        int x,y;
        g<<euclid_extins(a,b,x,y)<<'\n';
    }
    return 0;
}
