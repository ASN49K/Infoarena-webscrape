#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int main() {
  int n, m;
  cin >> n >> m;
  vector< int > v1(n + 1);
  vector< int > v2(m + 1);

  for(int i = 1; i <= n; i ++) 
    cin >> v1[i];
  for(int i = 1; i <= m; i ++) 
    cin >> v2[i];

  vector< vector< int > > dp(n + 1, vector< int >(m + 1, 0));

  int best = 0;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++){
      if(v1[i] == v2[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else{
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  cout << dp[n][m] << '\n';

  int cnt = dp[n][m];
  vector< int > sol(min(n, m) + 1);
  int a = n;
  int b = m;

  while(cnt > 0) {
    bool found = false;
    for(int i = a; i >= 1; i --) {
      if(found)
        break;
      for(int j = b; j >= 1; j--) {
        if(dp[i][j] != cnt)
          break;
        if(v1[i] == v2[j]) {
          sol[cnt --] = v1[i];
          found = true;
          a = i - 1;
          b = j - 1;
          break;
        }
      }
    }
  }
  for(int i = 1; i <= dp[n][m]; i ++)
    cout << sol[i] << ' ';
}