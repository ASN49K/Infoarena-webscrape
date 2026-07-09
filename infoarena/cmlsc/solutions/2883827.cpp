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

void findPath(int i, int j, std::ostream& os) {
  if (i == 0 || j == 0)
    return;

  if (a[i] == b[j]) {
    findPath(i - 1, j - 1, os);

    os << a[i] << ' ';

    return;
  }

  if (dp[i - 1][j] >= dp[i][j - 1])
    findPath(i - 1, j, os);
  else
    findPath(i, j - 1, os);
}

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

  out << dp[n][m] << '\n';

  findPath(n, m, out);
  
  return 0;
}