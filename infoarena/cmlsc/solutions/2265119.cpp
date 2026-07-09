#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    long i, j, n, m, v[256], a[256], k=0, p[256];
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(j=1;j<=m;j++)
        f>>a[j];
    if(n>m)
    {
        for(j=1;j<=m;j++)
            for(i=1;i<=n;i++)
        {
            if(a[j]==v[i])
            {
                p[k]=a[j];
                k++;
            }
        }
    }
    else
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
        {
            if(v[i]==a[j])
            {
                p[k]=v[i];
                k++;
            }
        }
    }
    g<<k<<endl;
    for(i=0;i<k;i++)
        g<<p[i]<<" ";
    return 0;
}
