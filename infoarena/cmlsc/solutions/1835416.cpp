#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],D[1025][1025],sir[1025],r;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           if(a[i]==b[j])
           D[i][j]=1+D[i-1][j-1];
           else
            D[i][j]=max(D[i-1][j],D[i][j-1]);
    for(int i=n,j=m; i&&j; )
        if(a[i]==b[j])
            sir[++r]=a[i],i--,j--;
        else if(D[i-1][j]<D[i][j-1])
            j--;
        else
            i--;
    g<<r<<'\n';
    for(int i=r;i>=1;i--)
        g<<sir[i]<<" ";
    return 0;

}
