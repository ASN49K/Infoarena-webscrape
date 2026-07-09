#include <algorithm>
#include <fstream>
#include <vector>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

const int MAX_N = 1025;

int n, m;
int a[MAX_N], b[MAX_N];
int dp[MAX_N][MAX_N];

std::vector<int> ans;

int main(){

  fin >> n >> m;
  for (int i = 1; i <= n; i++)
    fin >> a[i];
  for (int i = 1; i <= m; i++)
    fin >> b[i];
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
  int i = n;
  int j = m;
  while (i > 0 && j > 0)
    if (a[i] == b[j]) {
      ans.push_back(a[i]);
      i--;
      j--;
    } else if (dp[i - 1][j] < dp[i][j - 1])
      j--;
    else
      i--;
  fout << ans.size() << '\n';
  std::reverse(ans.begin(), ans.end());
  for (int i : ans)
    fout << i << " ";


  return 0;
}
