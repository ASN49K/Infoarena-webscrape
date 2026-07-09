#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1025][1025];
int A[1025];
int B[1025];
vector<int> ans;
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>A[i];
    }
    for(int j=1;j<=m;j++)
    {
        fin>>B[j];
    }
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=m+1;j++)
        {
            if(A[i-1]==B[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=n+1;i>=2;)
    {
        for(int j=m+1;j>=2;)
        {
            if(A[i-1]==B[j-1])
            {
                ans.push_back(A[i-1]);
                //cout<<i<<' ';
                i--;
                j--;
            }
            else if(dp[i-1][j]<dp[i][j-1]) j--;
            else i--;
        }
    }
    reverse(ans.begin(),ans.end());
    fout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++)
    {
        fout<<ans[i]<<' ';
    }
    return 0;
}
