#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,x,y,m,j,b,i,c,z,l,t[1001],a,v[1001],ok=0,d,r;

int main()
{
    f>>n;
    for (i=1;i<=n;i++)
    {
        f>>a>>b;
        r=0;
        r=a%b;
        while (r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<endl;
    }
}
