#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int d[1027][1027],a[1027],b[1027],v[1027],n,m,i,j,k;

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];

    for(i=1; i<=m; i++)
        f>>b[i];

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(b[i]==a[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    g << d[m][n] << '\n';
    while(m!=0 && n!=0)
    {
        if(a[n]==b[m])
        {
            v[++k]=a[n];
            m--;
            n--;
        }
        else if(d[m-1][n]>d[m][n-1])
            m--;
        else
            n--;
    }
    for(i=k;i>=1;i--)
        g<<v[i]<<" ";
    return 0;
}
