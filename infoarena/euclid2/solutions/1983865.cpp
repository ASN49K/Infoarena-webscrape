#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,x,y;

int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>x>>y,g<<cmmdc(x,y)<<'\n';
    return 0;
}
