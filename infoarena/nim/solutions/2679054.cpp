#include <bits/stdc++.h>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int n,m,nr;
int main()
{
    int i,j,t,z,k;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>n;
        z=0;
        for(j=1;j<=n;j++)
        {
            f>>k;
            z=(z^k);
        }
        if(z==0)
            g<<"NU";
        else
            g<<"DA";
        g<<'\n';
    }
}
