#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1500][1500],n,m;
int a[1500],b[1500];
void afis1()
{
    int l,i,j;
    l=dp[0][0];
    fout<<l<<'\n';
    i=0;j=0;
    while(l)
    {
        if(a[i]==b[j]){fout<<a[i]<<" ";l--;i++;j++;}
        else if(dp[i+1][j]>dp[i][j+1])i++;
        else j++;
    }
}
int main()
{
    int i,j;
    fin>>n>>m;
    for(i=0;i<n;i++)fin>>a[i];
    for(i=0;i<m;i++)fin>>b[i];
    for(i=n-1;i>=0;i--)
    {
        for(j=m-1;j>=0;j--)
        {
            if(a[i]==b[j])dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    //fout<<dp[0][0];
    //afis(0,0,dp[0][0]);
    afis1();
    return 0;
}
