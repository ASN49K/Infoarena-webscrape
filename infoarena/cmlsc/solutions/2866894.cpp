#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,v[1025],a[1025],d[1025],lcs[1025][1025];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f>>v[i];
    }
    for(int i=1;i<=m;i++)
    {
        f>>a[i];
    }
    for(int k=1; k<=n; k++)
    {
        for(int h=1; h<=m; h++)
        {
            if(v[k]==a[h])lcs[k][h]=1+lcs[k-1][h-1];
            else if(lcs[k-1][h]>lcs[k][h-1])lcs[k][h]=lcs[k-1][h];
            else lcs[k][h]=lcs[k][h-1];
        }
    }
    g<<lcs[n][m]<<'\n';
    int i=0,k=n,h=m;
    while(lcs[k][h] && k>0 && h>0)
    {
        if(v[k]==a[h])
        {
            d[++i]=v[k];k--;h--;
        }
        else if(lcs[k][h]==lcs[k-1][h])k--;
        else h--;
    }
    for(int k=i;k>=1;k--)g<<d[k]<<" ";
    return 0;
}
