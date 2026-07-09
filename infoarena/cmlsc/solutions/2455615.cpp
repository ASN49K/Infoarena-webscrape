#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1050],b[1050],dp[1050][1050];
vector<int> sol;
int main()
{
    in >> n >> m;
    for(int i=1; i<=n; i++)
        in >> a[i];
    for(int i=1; i<=m; i++)
        in >> b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=n, j=m; i&&j;)
    {
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    out << sol.size() << '\n';
    for(int i=sol.size()-1; i>=0; i--)
        out << sol[i] << ' ';
    return 0;
}
