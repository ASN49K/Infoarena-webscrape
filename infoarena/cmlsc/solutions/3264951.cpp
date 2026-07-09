#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int NMAX = 1026;
int n,m,a[NMAX],b[NMAX],dp[NMAX][NMAX];

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
        maxSelf(dp[i][j], 1 + dp[i-1][j-1]);
      }
      maxSelf(dp[i][j], dp[i-1][j]);
      maxSelf(dp[i][j], dp[i][j-1]);
    }
  }
  fout << dp[n][m] << "\n";
  int i = n, j = m;
  vector<int> ans;
  while(i > 0 && j > 0){
    if(a[i] == b[j]){
      ans.push_back(a[i]);
      i--, j--;
    }else if(dp[i-1][j] > dp[i][j-1]){
      i--;
    }else{ // dp[i-1][j] < dp[i][j-1]
      j--;
    }
  }
  reverse(all(ans));
  for(int it: ans){
    fout << it << " ";
  }
  return 0;
}
