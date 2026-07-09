#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
long long dp[1025][1025],a[1025],b[1025];
vector<int> c;
int main ()
{
    long long i,j,n,m;
    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>a[i];
    for (i=1;i<=m;i++)
        fin>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else       dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    i=n,j=m;
    while (i>=1 &&j>=1)
    {
        if (dp[i][j]==dp[i-1][j])
            i--;
        else
            if (dp[i][j]==dp[i][j-1])
            --j;
        else
        {
            c.push_back(b[j]);
            --i,j--;
        }
    }
    fout<<dp[n][m]<<'\n';
    n=c.size()-1;
    for (;n>=0;--n)
        fout<<c[n]<<' ';
    fout<<'\n';

}
