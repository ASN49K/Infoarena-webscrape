#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1030],b[1030],n,m;
int dp[1030][1030];
int v[1030],top;

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    int i=n;
    int j=m;
    while(i!=0&&j!=0)
    {
        if(dp[i-1][j]<dp[i][j])
        {
            v[++top]=a[i];
            i--;
        }
        else if(dp[i][j-1]<dp[i][j])
        {
            v[++top]=a[i];
            j--;
        }
        else i--;
    }
    fout<<top<<"\n";
    for(int i=top;i>=1;i--)
        fout<<v[i]<<" ";

    return 0;
}
