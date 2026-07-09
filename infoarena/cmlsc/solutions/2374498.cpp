#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMAX = 1e3 + 1e2;

int n, m;

int a[1 + NMAX];
int b[1 + NMAX];
int dp[1 + NMAX][1 + NMAX];

int str[1 + NMAX];
int best;

int main()
{
  in >> m >> n;

  for(int i = 1; i <= m; i++)
    in >> a[i];

  for(int i = 1; i <= n; i++)
    in >> b[i];

  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(a[i] == b[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  for(int i = m, j = n; i != 0;) {
    if(a[i] == b[j]) {
      str[++best] = a[i];
      i--;
      j--;
    } else if(dp[i - 1][j] < dp[i][j - 1]) {
      j--;
    } else {
      i--;
    }
  }

  out << best << '\n';

  for(int i = best; i >= 1; i--)
    out << str[i] << ' ';

  out << '\n';

  in.close();
  out.close();

  return 0;
}
