#include <fstream>
#include <vector>

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
  vector< pair< int, int > > sol(max(n, m) + 1);
  int cnt = 0;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++){
      if(v1[i] == v2[j]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if((i > sol[cnt].first and j > sol[cnt].second) or cnt == 0) {
          pair< int, int > p = make_pair(i, j);
          sol[++ cnt] = p;
        }
      }
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }

  cout << dp[n][m] << '\n';
  if(cnt > 0) {
      for(int i = 1; i <= cnt; i ++)
        cout << v1[sol[i].first] << ' ';
      cout << '\n';
  }
}