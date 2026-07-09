#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1025][1025];
int a[1025],b[1025];
vector<int>v;
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int i=n,j=m;
    while(dp[i][j])
    {
        if(a[i]==b[j])
        {
            v.push_back(a[i]);
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else j--;
    }
    fout<<v.size()<<'\n';
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        fout<<v[i]<<' ';
    return 0;
}
