#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T, i, a, b, cmmdc(int,int);
int main()
{
    f>>T;
    for (i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
int cmmdc(int a,int b)
{
    if(b==0)return a;
    return cmmdc(b,a%b);
}
