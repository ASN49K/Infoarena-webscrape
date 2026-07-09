#include <bits/stdc++.h>

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

const int maxn = 1024;

int n, m, a[maxn + 1], b[maxn + 1], d[maxn + 1][maxn + 1];

void dfs(int row, int col, int step) {
  if (step == 0) {
    return;
  }

  if (a[ row ] == b[ col ]) {
    dfs(row - 1, col - 1, step - 1);
    fo << a[ row ] << ' ';
    return;
  }

  if (d[row - 1][ col ] == d[ row ][ col ]) {
    dfs(row - 1, col, step);
    return;
  }

  dfs(row, col - 1, step);
}

int main()
{
  fi >> n >> m;
  for (int i = 1; i <= n; i++) {
    fi >> a[ i ];
  }

  for (int i = 1; i <= m; i++) {
    fi >> b[ i ];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[ i ] == b[ j ]) {
        d[ i ][ j ] = 1 + d[i - 1][j - 1];
      }
      else {
        d[ i ][ j ] = max(d[i - 1][ j ], d[ i ][j - 1]);
      }
    }
  }

  fo << d[ n ][ m ] << '\n';

  dfs(n, m, d[ n ][ m ]);

  return 0;
}
