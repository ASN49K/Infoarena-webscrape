#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

const int NMAX = 1025;
int v[NMAX], a[NMAX], d[NMAX][NMAX];
int dir[NMAX][NMAX];

vector<int> sol;

int line[] = {-1, -1, 0};
int col[] = {-1, 0, -1};

int main() {
  int n, m;
  ifstream cin("cmlsc.in");
  ofstream cout("cmlsc.out");
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> v[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == v[j]) {
        d[i][j] = d[i - 1][j - 1] + 1;
        dir[i][j] = 0;
      } else if (d[i - 1][j] > d[i][j - 1]) {
        d[i][j] = d[i - 1][j];
        dir[i][j] = 1;
      } else {
        d[i][j] = d[i][j - 1];
        dir[i][j] = 2;
      }
    }
  }

  cout << d[n][m] << '\n';

  int i = n, j = m;

  while (i != 0 && j != 0) {
    if (a[i] == v[j]) {
      sol.push_back(a[i]);
    }

    int auxi = i;
    i += line[dir[i][j]];
    j += col[dir[auxi][j]];
  }

  for (int i = sol.size() - 1; i >= 0; i--) {
    cout << sol[i] << " ";
  }

  return 0;
}