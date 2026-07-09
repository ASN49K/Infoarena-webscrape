#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define N_MAX 1024
int a[N_MAX], b[N_MAX], dp[N_MAX][N_MAX], arr[N_MAX];

int main()
{
  int m, n, res, c, d, i, j, cval, pos;
  fin >> m >> n;
  for(i = 1; i <= m; ++i) {
    fin >> a[i];
  }
  for(i = 1; i <=  n; ++i) {
    fin >> b[i];
  }

  res = c = d = 0;
  dp[0][0] = 0;
  for(i = 1; i <= m; ++i) {
    for(j = 1; j <= n; ++j) {
      if(a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if(dp[i][j] > res) {
          res = dp[i][j];
          c = i;
          d = j;
        }
      }else{
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  fout << res << '\n';

  cval = dp[m][n];
  i = m;
  j = n;
  pos = 0;
  while(cval > 0) {
    if(dp[i - 1][j] == cval) {
      --i;
    }else if(dp[i][j - 1] == cval) {
      --j;
    }else{
      arr[pos++] = a[i];
      cout << a[i] << '\n';
      --i, --j;
      --cval;
    }
  }

  for(i = pos - 1; i >= 0; --i) {
    fout << arr[i] << ' ';
  }

  return 0;
}
