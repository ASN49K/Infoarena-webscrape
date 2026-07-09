#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1025],b[1025],v[1025][1025],sir[1025],i,j,k;
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int i=1; i<=m; i++)
        f>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    int i=n,j=m;
    while(i and j)
    {
        if(a[i]==b[j])
            sir[++k]=a[i],i--,j--;
        else if(v[i-1][j]<v[i][j-1])
            j--;
        else
            i--;
    }
    g<<k<<'\n';
    for(int i=k; i>=1; i--)
        g<<sir[i]<<" ";
    return 0;
}
