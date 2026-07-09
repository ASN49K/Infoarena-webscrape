#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short n,m,a[1025],b[1025],A[1025][1025];

void rfcsbs(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(a[i]==b[j])
    {
        rfcsbs(i-1,j-1);
        g<<a[i]<<" ";
    }
    else
    {
        if(A[i-1][j]>A[i][j-1])
            rfcsbs(i-1,j);
        else rfcsbs(i,j-1);
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j]) A[i][j]=1+A[i-1][j-1];
        else A[i][j]=max(A[i-1][j],A[i][j-1]);
    }
    g<<A[n][m]<<'\n';
    rfcsbs(n,m);
    return 0;
}
