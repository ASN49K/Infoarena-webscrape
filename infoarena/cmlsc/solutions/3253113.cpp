#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1027;
using pii = pair<int, int>;
int n,m,a[NMAX],b[NMAX];
pair<int, pii> dp[NMAX][NMAX];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

template<typename T>
void maxSelf(T &a, T b){
  a = max(a, b);
}

int main() {
  fin >> n >> m;
  for(int i = 1; i <= n; i++){
    fin >> a[i];
  }
  for(int i = 1; i <= m; i++){
    fin >> b[i];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i] == b[j]){
        maxSelf(dp[i][j], {1 + dp[i-1][j-1].first, {i, j}});
      }
      maxSelf(dp[i][j], dp[i-1][j]);
      maxSelf(dp[i][j], dp[i][j-1]);
    }
  }
  int len = dp[n][m].first;
  vector<int> ans;
  auto [x, y] = dp[n][m].second;
  while(x != 0){
    ans.push_back(a[x]);
    tie(x, y) = dp[x-1][y-1].second;
  }
  fout << len << "\n";
  for(int i = len-1; i >= 0; i--){
    fout << ans[i] << " ";
  }
  return 0;
}
