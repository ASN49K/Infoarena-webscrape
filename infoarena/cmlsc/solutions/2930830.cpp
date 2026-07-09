#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[1025], b[1025], dp[1025][1025];

void read() {
  f>>n>>m;
  for(int i = 1;i <= n;++i) {
    f>>a[i];
  }
  for(int i = 1;i <= m;++i) {
    f>>b[i];
  }
  f.close();
}

void compute() {
  for(int i = 1;i <= n;++i) {
    for(int j = 1;j <= m;++j) {
      if(a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
}

void reconstruct(int i, int j) {
  if(!i || !j) {
    return;
  }

  if(a[i] == b[j]) {
    reconstruct(i - 1, j - 1);
    g<<a[i]<<" ";
    return;
  }
  
  if(dp[i - 1][j] > dp[i][j - 1]) {
    reconstruct(i - 1, j);
  } else {
    reconstruct(i, j - 1);
  }
}

void solve() {
  compute();
  g<<dp[n][m]<<'\n';
  reconstruct(n, m);
  g.close();
}

int main() {
  read();
  solve();
  return 0;
}
