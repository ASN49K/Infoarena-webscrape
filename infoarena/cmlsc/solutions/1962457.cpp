#include <fstream>
#define MAX 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, i, j, a[MAX], e[MAX][MAX], b[MAX], v[MAX], k;

int main()  {
  fin >> n >> m;
  for (i = 1; i <= n; i++)
    fin >> a[i];
  for (i = 1; i <= m; i++)
    fin >> b[i];
  for (i = 1; i <= n; i++)  {
    for (j = 1; j <= m; j++)  {
      if (a[i] == b[j]) {
        e[i][j] = e[i - 1][j - 1] + 1;
      }
      else
        e[i][j] = max(e[i - 1][j], e[i][j - 1]);
    }
  }
  i = n; j = m;
  while (e[i][j] > 0) {
    if (e[i - 1][j] < e[i][j] && e[i][j - 1] < e[i][j])
      v[++k] = a[i], i--, j--;
    else  {
      while (e[i - 1][j] == e[i][j])
        i--;
      while (e[i][j - 1] == e[i][j])
        j--;
    }
  }
  fout << e[n][m] << '\n';
  for (; k; k--)
    fout << v[k] << ' ';
}
