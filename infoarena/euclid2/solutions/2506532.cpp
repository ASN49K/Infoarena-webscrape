#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,t,cmmdc(int,int);
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
int cmmdc(int a,int b)
{
    if(b==0)return a;
    return cmmdc(b,a%b);
}
