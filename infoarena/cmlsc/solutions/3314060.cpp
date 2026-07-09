#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
vector<int>ans;
int a[1024],b[1024],n,m;
int dp[1024][1024];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }*/

    int i=n,j=m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            ans.push_back(a[i]);
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(),ans.end());
    fout << ans.size() << '\n';
    for(auto i : ans)
        fout << i << ' ';
    return 0;
}
