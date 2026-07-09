#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int i,j,n,m,k;
int v[1050][1050],a[1050],b[1050];

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            v[i][j]=v[i-1][j-1]+1;
        else
            v[i][j]= max(v[i][j-1],v[i-1][j]);
    }
    g<<v[n][m]<<"\n";
    k=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i][j]==k)
            {
                k++;
                g<<a[i]<<" ";
            }
        }
    }
    return 0;
}
