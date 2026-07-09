#define d(x) std::cout << x << std::endl
#define dm(msg, x) std::cout << msg << x << std::endl

#define all(a) a.begin(), a.end()
#define range(a, l, r) a.begin() + l, a.begin() + r
#define aall(a, n) a + 1, a + 1 + n
#define arange(a, l, r) a + l, a + r
	
#define maxself(a, b) a = std::max(a, b);
#define minself(a, b) a = std::min(a, b);

#define inout(f) std::ifstream in((f) + (std::string) ".in");std::ofstream out((f) + (std::string) ".out")

#include <iostream>
#include <fstream>

const int NMAX = 1024;

int n, m;

int a[1 + NMAX];
int b[1 + NMAX];

int dp[1 + NMAX][1 + NMAX];
// dp[i][j] - best common subsequence from a[1..i] and b[1..j]

int ans[1 + NMAX];

int main() {
  inout("cmlsc");

  in >> n >> m;

  for (int i = 1; i <= n; ++i)
    in >> a[i];

  for (int j = 1; j <= m; ++j)
    in >> b[j];

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];

      else 
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (dp[i][j] == dp[i - 1][j - 1] + 1 && dp[i][j] == dp[i][j - 1] + 1 && dp[i][j] == dp[i - 1][j] + 1)
        ans[dp[i][j]] = a[i]; // = b[j]
    }
  }

  out << dp[n][m] << '\n';
  for (int i = 1; i <= dp[n][m]; ++i)
    out << ans[i] << ' ';
  out << '\n';
  
  return 0;
}