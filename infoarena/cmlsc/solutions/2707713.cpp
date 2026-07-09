#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1026][1026];
vector <int> sol;

int main()
{
    int n,m;
    int a[1026],b[1026];
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>a[i];
    for(int i=1;i<=m;i++) fin>>b[i];

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
    while(i>=1 && j>=1)
    {
        if(dp[i-1][j]==dp[i][j-1] && dp[i-1][j]!=dp[i][j]){
            sol.push_back(a[i]);
            i--,j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    fout<<dp[n][m]<<"\n";
    reverse(sol.begin(),sol.end());
    for(int i=0;i<sol.size();i++)
        fout<<sol[i]<<" ";
    return 0;
}
