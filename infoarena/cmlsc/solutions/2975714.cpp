#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1026],b[1026],dp[1026][1026],M,N,L;
int main()
{   fin>>M>>N;
for(int i=1;i<=M;i++)
{
    fin>>a[i];
}
for(int i=1;i<=N;i++)
{
    fin>>b[i];
}
vector<int> sol;
for(int i=1;i<=M;i++)
{
    for(int j=1;j<=N;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        if(dp[i][j]>dp[i-1][j] && dp[i][j]>dp[i][j-1] && a[i]==b[i])
            sol.push_back(a[i]);

    }
}
fout<<dp[M][N]<<endl;
for(auto i:sol)
    fout<<i<<" ";

    return 0;
}
