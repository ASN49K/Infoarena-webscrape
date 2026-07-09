#include <fstream>
#include <cmath>

std::ifstream cin("cmlsc.in");
std::ofstream cout("cmlsc.out");

int m, n, p, a[1024], b[1024], x[1024][1024], y[1024];

int main() {
  cin >> m >> n;
  for (int i {1}; i <= m; ++i) cin >> a[i];
  for (int i {1}; i <= n; ++i) cin >> b[i];
  
  for (int i {1}; i <= m; ++i)
    for (int j {1}; j <= n; ++j)
      if (a[i] == b[j]) x[i][j] = 1 + x[i - 1][j - 1];
      else x[i][j] = std::max(x[i - 1][j], x[i][j - 1]);
      
  for (int i {m}, j {n}; i, j;)
    if (a[i] == b[j]) y[++p] = a[i], --i, --j;
    else if (x[i - 1][j] > x[i][j - 1]) --i;
    else --j;
  
  cout << p << "\n";
  for (int i {p}; i >= 1; --i)
    cout << y[i] << " ";
  
  cin.close();
  cout.close();
  return 0;
}