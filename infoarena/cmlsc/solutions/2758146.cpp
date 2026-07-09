#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N=1025;
int n,m,a[N],b[N],d[N][N],sol[N];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int j=1;j<=m;j++)
        f>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]!=b[j])
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            else
                d[i][j]=d[i-1][j-1]+1;
        }
    int k=d[n][m];
    g<<k<<'\n';

    int i=n,j=m;
    while(d[i][j]!=0)
    {
        if(a[i]==b[j])
        {
            sol[d[i][j]]=a[i];
            i--;j--;
        }
        else
            if(d[i-1][j]>=d[i][j-1])
                i--;
            else
                j--;
    }
    for(int i=1;i<=k;i++)
        g<<sol[i]<<' ';
    return 0;
}
