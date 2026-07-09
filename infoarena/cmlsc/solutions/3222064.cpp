#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,k,a[1030],b[1030],rez[1030],dp[1030][1030];
///dp[i][j]=lg subsir comun din primele i el din a si primele j el din b
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n,j=m;
    while(i>=1 and j>=1)
    {
        if(a[i]==b[j])
        {
            rez[++k]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    g<<k<<'\n';
    for(int i=k;i>=1;i--)
        g<<rez[i]<<" ";
    return 0;
}
