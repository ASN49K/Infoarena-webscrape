#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t, n, a[100001], i;

int main()
{
  fin >> t;
  for (int tt = 1; tt <= t; tt++) {
    fin >> n;
    for (i = 1; i <= n; i++)
      fin >> a[i];
    i = 1;
    while (a[i] == 1 and i <= n - 1)
      i++;
    if (i % 2 == 1)
      fout << "DA" << '\n';
    else
      fout << "NU" << '\n';
  }
  return 0;
}
