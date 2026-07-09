#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int maxVal = 1025;

int main()
{
  int n, m, mat[maxVal][maxVal] = {0}, v[maxVal], w[maxVal], i, j, stiva[maxVal], k = 0;
  fin >> n >> m;
  for (i = 1; i <= n; i++)
    fin >> v[i];
  for (i = 1; i <= m; i++)
    fin >> w[i];
  int curent = 0;
  for (i = n; i >= 1; i--)
  {
    for (j = m; j >= 1; j--)
    {
      if (v[i] == w[j])
      {
        mat[i][j] = mat[i + 1][j + 1] + 1;
      }
      else
        mat[i][j] = max(mat[i+1][j], mat[i][j+1]);
    }
  }
  for (i = 1; i <= n; i++)
    cout << v[i] << ' ';
  cout << '\n';
  for (i = 1; i <= m; i++)
    cout << w[i] << ' ';
  cout << '\n';
  for (i = n; i >= 1; i--)
  {
    for (j = m; j >= 1; j--)
    {
      if (v[i] == w[j])
      {
        stiva[++k] = v[i];
        n--, m--;
      }
    }
  }
  if (v[1] == w[1])
    stiva[++k] = v[1];
  cout << mat[1][1] << '\n';
  for (i = k; i >= 1; i--)
    cout << stiva[i] << ' ';
  return 0;
}