#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
const int Nmax = 1050;

int A[Nmax], B[Nmax], ret[Nmax];
int d[Nmax][Nmax];


inline int get(int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  else return d[i][j];
}

inline int max(int x, int y) { return x > y ? x : y; }

int main() {
  ifstream fin ("cmlsc.in");
  ofstream fout ("cmlsc.out");

  int n, m;
  fin >> n >> m;
  for (int i = 0; i < n; i++)
    fin >> A[i];
  for (int j = 0; j < m; j++)
    fin >> B[j];

  for(int i = 0; i < n; i++)
  for(int j = 0; j < m; j++) {
    if (A[i] == B[j])
      d[i][j] = get(i-1, j-1) + 1;
    else
      d[i][j] = max(get(i-1, j), get(i, j-1));
  }

  int ans = d[n-1][m-1];
  fout << ans << '\n';

  int i = n-1, j = m-1, x = ans;
  while (x > 0) {
    if (A[i] == B[j]) {
      x--;
      ret[x] = A[i];
      i--;
      j--;
    } else {
      if (d[i][j] == get(i-1, j))
        i--;
      else
        j--;
    }
  }
  for (int i = 0; i < ans; i++) {
    fout << ret[i] << ((i == ans - 1) ? '\n' : ' ');
  }

  return  0;
}