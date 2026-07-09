#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,cmmdc(int,int);

int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
   return 0;
}
int cmmdc(int a,int b)
{
    if(!b)return a;
    return cmmdc(b,a%b);
}
