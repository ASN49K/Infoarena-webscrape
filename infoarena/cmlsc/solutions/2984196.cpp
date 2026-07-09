#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MaxN = 1025;

int n, m;
int a[MaxN], b[MaxN], dp[MaxN][MaxN];
vector<int> ans;

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    fin >> a[i];
  }

  for (int j = 1; j <= m; ++j) {
    fin >> b[j];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  for (int i = n, j = m; i;) {
    if (a[i] == b[j]) {
      ans.push_back(a[i]);
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      --i;
    } else {
      --j;
    }
  }

  fout << ans.size() << '\n';
  for (auto i : ans) {
    fout << i << ' ';
  }
  fout << '\n';
  return 0;
}
