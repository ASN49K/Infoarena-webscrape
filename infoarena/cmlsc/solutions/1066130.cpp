#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1030], b[1030], dp[1030][1030];

int main(){
  ifstream in("cmlsc.in");
  ofstream out("cmlsc.out");

  int n, m;
  in >> n >> m;

  for(int i = 1; i <= n; ++i)
    in >> a[i];
  for(int i = 1; i <= n; ++i)
    in >> b[i];

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      if(a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  vector<int> ans;
  int x = n, y = m;
  while(x && y){
    if(a[x] == b[y]){
      ans.push_back(a[x]);
      --x;
      --y;
    }
    else{
      if(dp[x - 1][y] > dp[x][y - 1])
        --x;
      else
        --y;
    }
  }

  out << ans.size() << "\n";

  for(int i = ans.size() - 1; i >= 0; --i)
    out << ans[i] << " ";

  return 0;
}
