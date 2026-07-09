#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int s1[1050], s2[1050], dp[1050][1050];

int main(){
  ifstream in("cmlsc.in");
  ofstream out("cmlsc.out");

  int n, m;
  in >> n >> m;

  for(int i = 1; i <= n; ++i)
    in >> s1[i];
  for(int i = 1; i <= m; ++i)
    in >> s2[i];

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      if(s1[i] == s2[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  int ans = dp[n][m];

  out << ans << "\n";

  vector<int> recon;
  int px = n, py = m;

  while(ans){
    if(s1[px] == s2[py]){
      recon.push_back(s1[px]);
      --ans;
      --px;
      --py;
    }
    else{
      if(dp[px - 1][py] > dp[px][py - 1])
        --px;
      else
        --py;
    }
  }

  for(int i = recon.size() - 1; i >= 0; --i)
    out << recon[i] << " ";

  return 0;
}
