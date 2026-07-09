#include <bits/stdc++.h>
using namespace std;
ifstream f ("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,i;
int euclid(int a,int b)
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
    for(i=1; i<=n; i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
}
