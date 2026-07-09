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
  for (i = n; i >= 1; i--)
  {
    for (j = m; j >= 1; j--)
    {
      if (v[i] == w[j])
      {
        stiva[++k] = v[i];
        mat[i][j] = max(mat[i+1][j], mat[i][j+1]) + 1;
      }
      else
        mat[i][j] = max(mat[i+1][j], mat[i][j+1]);
    }
  }
  fout << mat[1][1] << '\n';
  for (i = k; i >= 1; i--)
    fout << stiva[i] << ' ';
  return 0;
}