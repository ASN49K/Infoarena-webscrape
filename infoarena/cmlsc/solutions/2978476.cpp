#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,x,ap[257],k,v[1025];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f>>x;
        ap[x]++;
    }
    for(int i=1;i<=m;i++)
    {
        f>>x;
        if(ap[x])
        {
            v[++k]=x;
            ap[x]--;
        }
    }
    g<<k<<'\n';
    for(int i=1;i<=k;i++)
        g<<v[i]<<" ";
    return 0;
}
