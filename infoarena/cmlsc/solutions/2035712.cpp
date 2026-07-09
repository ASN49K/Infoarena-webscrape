#include <bits/stdc++.h>
using namespace std;
int a[1100], b[1100];
int dp[1100][1100];
int n, m;
int r[1100];
int main()
{
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
cin >> n >> m;
for (int i=1; i <= n; i++)
cin >> a[i];
for (int i=1; i <= m; i++)
cin >> b[i];
a[0] = b[0] = -1;
for (int i=1; i <= n; i++)
{
for (int j=1; j <= m; j++)
{
if (a[i] == b[j])
dp[i][j] = 1 + dp[i - 1][j - 1];
else
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}
}
int ans = dp[n][m];
int cnt(ans);
cout << ans << '\n';
for (int i=n, j=n; i>0 && j>0;i--,j--)
{
if (dp[i][j] == dp[i - 1][j])
{
i--;
continue;
}
if (dp[i][j] == dp[i][j - 1])
{
j--;
continue;
}
r[cnt--] = a[i];
i--;
j--;
}
for (int i=1; i <= ans; i++)
cout << r[i] <<" ";
return 0;
}
