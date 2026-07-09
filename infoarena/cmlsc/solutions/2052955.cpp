#include <bits/stdc++.h>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int a[201],b[201],c[101][101],n,i,j,k,x,mx,m,smx;
void tipar(int i, int j)
{
    if(i>=1 && j>=1)
        if(a[i]!=b[j])
        {
            if(c[i][j-1]>c[i-1][j]) tipar(i,j-1);
            else tipar(i-1,j);
        }
        else
        {
            tipar(i-1,j);
            g<<a[i]<<" ";
        }
}
int main()
{
    f>>m>>n;
    for(i=1; i<=m; i++) f>>a[i];
    for(j=1; j<=n; j++) f>>b[j];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[m][n]<<'\n';
    tipar(m,n);
    return 0;
}
