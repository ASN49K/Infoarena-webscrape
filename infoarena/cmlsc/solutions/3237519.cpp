#include <bits/stdc++.h>

using namespace std;

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

const int DIM = 1025;

int dp[DIM][DIM];
int a[DIM], b[DIM];
int from[DIM][DIM];

int main() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  int n, m;

  fin >> n >> m;
  for ( int i = 1; i <= n; ++i ) fin >> a[i];
  for ( int i = 1; i <= m; ++i ) fin >> b[i];
  
  for ( int i = 1; i <= n; ++i ) {
	for ( int j = 1; j <= m; ++j ) {
	  if ( a[i] == b[j] ) {
		dp[i][j] = dp[i - 1][j - 1] + 1;
	  } else {
	    if ( dp[i - 1][j] > dp[i][j - 1] ) {
	      dp[i][j] = dp[i - 1][j];
		  from[i][j] = 1;
		} else {
		  dp[i][j] = dp[i][j - 1];
		  from[i][j] = 2;
		}
	  }
	}
  }
  fout << dp[n][m] << "\n";
  vector<int> sol;
  int i = n, j = m;
  while ( i > 0 && j > 0 ) {
	if ( from[i][j] == 0 ) {
	  sol.push_back(a[i]);
	  --i, --j;
	} else if ( from[i][j] == 1 ) {
	  --i;
	} else {
	  --j;
	}
  }
  reverse(sol.begin(), sol.end());
  for ( auto x : sol ) fout << x << " ";
  fin.close();
  fout.close();
  return 0;
}
