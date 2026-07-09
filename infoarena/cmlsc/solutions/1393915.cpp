#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream f{"cmlsc.in"};
  ofstream g{"cmlsc.out"};

  int m, n;
  f >> m >> n;

  vector<int> a(m), b(n);

  for (int i = 0; i < m; ++i)
  {
    f >> a[i];
  }

  for (int i = 0; i < n; ++i)
  {
    f >> b[i];
  }

  int best[m + 1][n + 1];

  for (int i = 0; i <= m; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      best[i][j] = 0;
    }
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      best[i][j] = max(best[i - 1][j], best[i][j - 1]);
      if (a[i - 1] == b[j - 1])
        best[i][j] = max(1 + best[i - 1][j - 1], best[i][j]);
    }
  }

  g << best[m][n] << endl;
  int i = m;
  int j = n;
  deque<int> sol;
  while (i != 0 && j != 0) {
    if (a[i - 1] == b[j - 1] && best[i - 1][j - 1] + 1 == best[i][j]) {
      sol.push_front(a[i - 1]);
      i--;
      j--;
    } else if (best[i - 1][j] == best[i][j])
      i--;
    else 
      j--;
  }

  for (int i = 0; i < sol.size() - 1; i++) {
    g << sol[i] << " ";
  }
  if (sol.size() > 0)
    g << sol[sol.size() - 1] << endl;

  return 0;
}
