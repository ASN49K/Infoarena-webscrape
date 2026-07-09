#include <bits/stdc++.h>
#define maxn 1024

using namespace std;

int dp[maxn+5][maxn+5], a[maxn+5], b[maxn+5];
vector <int> sol;

int main ()
{
  ifstream fin ( "cmlsc.in" );
  ofstream fout ( "cmlsc.out" );

  int n, m; fin >> n >> m;
  int i, j, z;
  for ( i = 1; i <= n; i++ ) fin >> a[i];
  for ( i = 1; i <= m; i++ ) fin >> b[i];

  for ( i = 1; i <= n; i++ )
    for ( j = 1; j <= m; j++ )
    {
      if ( a[i] == b[j] ) dp[i][j] = 1 + dp[i-1][j-1];
      dp[i][j] = max(dp[i][j], max(dp[i-1][j],dp[i][j-1]));
    }

  for ( i = n, j = m; i > 0 && j > 0; )
  {
    if ( a[i] == b[j] ) sol.push_back (a[i]), i--, j--;
    else if ( dp[i-1][j] > dp[i][j-1] ) i--;
    else j--;
  }

  fout << dp[n][m] << '\n';
  reverse(sol.begin(), sol.end());
  for ( i = 0; i < (int) sol.size(); i++ ) fout << sol[i] << ' ';

  fin.close ();
  fout.close ();

  return 0;
}
