#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
vector<int> G[100005];

int a[1025], n, m, b[1025], ct;
int dp[1025][1025], sol[1025];

void DP()
{
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <=m; j++)
            if(a[i]==b[j])
                dp[i][j] = dp[i - 1][j - 1]  + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    fout << dp[n][m] << '\n';
    int i = n;
    int j = m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
            sol[++ct] = a[i], i--, j--;
        else
            if(dp[i-1][j] > dp[i][j - 1])
                i--;
            else
                j--;

    }
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    DP();
    for(int i = 1; i <= ct; i++)
        fout << sol[i]<<" ";
    return 0;
}
