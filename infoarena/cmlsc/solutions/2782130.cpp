#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,dp[1025][1025],a[1025],b[1025],r[1025],k;
int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)f>>a[i];
    for(j=1; j<=m; j++)f>>b[j];
    dp[0][0]=dp[1][0]=dp[0][1]=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j])dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);


        }



    g<<dp[n][m]<<endl;;
    k=0;
    i=n;
    j=m;
    while(i!=0 and j!=0 and k<dp[n][m])
    {
        if(a[i]==b[j])
        {
            k++;
            r[k]=a[i];
            i--;
            j--;


        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])i--;
            else j--;



        }

    }
    for(i=k; i>=1; i--)g<<r[i]<<" ";

}
