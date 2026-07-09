#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int i,j,n,m,k;
int v[1050][1050],a[1050],b[1050],w[1050];

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
    i--;
    j--;
    k=0;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            w[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(v[i-1][j]>v[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=k;i>0;i--)
        g<<w[i]<<" ";
    return 0;
}
