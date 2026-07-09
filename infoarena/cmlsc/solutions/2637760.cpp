#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, a[1025], b[1025], r[1025], sclm[1025][1025], l;

int main()
{
  fin >> n >> m;
  for (int i = 1; i <= n; i++)
    fin >> a[i];
  for (int j = 1; j <= m; j++)
    fin >> b[j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] == b[j])
        sclm[i][j] = sclm[i - 1][j - 1] + 1;
      else
        sclm[i][j] = max (sclm[i - 1][j], sclm[i][j - 1]);
  for (int i = n, j = m; i >= 1;)
    if (a[i] == b[j]) {
      l++;
      r[l] = a[i];
      i--; j--;
    }
    else
      if (sclm[i - 1][j] < sclm[i][j - 1])
        j--;
      else
        i--;
  fout << l << '\n';
  for (; l >= 1; l--)
    fout << r[l] << ' ';
  return 0;
}
