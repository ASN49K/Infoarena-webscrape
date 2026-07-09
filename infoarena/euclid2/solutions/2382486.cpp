#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;
int cmmdc_rec(int x, int y)
{
    if(y==0) return x;
    return cmmdc_rec(y,x&y);
}
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>a>>b;
        g<<cmmdc_rec(a,b)<<'\n';
    }
    return 0;
}
