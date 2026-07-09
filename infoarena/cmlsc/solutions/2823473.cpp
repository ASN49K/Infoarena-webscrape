#include<bits/stdc++.h>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1026],b[1026],n,m,dp[1026][1026],nou[1026];

int main()
{
    int i,j,k=0;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    dp[0][0]=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    g<<dp[m][n]<<'\n';
    for(i=m,j=n; i>0; )
    {
        if(a[i]==b[j])
        {
            k++;
            nou[k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=k;i>=1;i--)
        g<<nou[i]<<" ";
    return 0;
}
