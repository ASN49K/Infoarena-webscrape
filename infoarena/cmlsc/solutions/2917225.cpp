#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int NM = 1024 + 5;

int a[NM], b[NM], dp[NM][NM];
int n, m;

int main(){
  fin >> n >> m;
  for (int i = 1; i <= n; i++){
    fin >> a[i];
  }
  for (int i = 1; i <= m; i++){
    fin >> b[i];
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (a[i] == b[j]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else{
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  fout << dp[n][m] << '\n';
  int l = n, c = m;
  vector<int>ans;
  while (dp[l][c] > 0){
    if (dp[l - 1][c - 1] + 1 == dp[l][c]){
      ans.push_back(a[l]);
      l -= 1; c -= 1;
    }
    else if (dp[l - 1][c] == dp[l][c]){
      l -= 1;
    }
    else{
      c -= 1;
    }
  }
  for (int i = (int)ans.size() - 1; i >= 0; i--){
    fout << ans[i] << " ";
  }
}
