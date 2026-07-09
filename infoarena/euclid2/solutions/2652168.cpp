#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    int t,x,y;
    f>>t;
    for(;t;t--)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';

    }
    return 0;
}
