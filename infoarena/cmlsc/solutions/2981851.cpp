#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1025],b[1025],v[1025],i,j,d[1025][1025],k;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int j=1;j<=m;j++)
        f>>b[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    int i=n;j=m;
    while(i and j)
    {
        if(a[i]==b[j])
        {
            v[++k]=b[j];
            i--;
            j--;
        }
        if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    g<<d[n][m]<<'\n';
    for(int i=k;i>=1;i--)
        g<<v[i]<<" ";
    return 0;
}
