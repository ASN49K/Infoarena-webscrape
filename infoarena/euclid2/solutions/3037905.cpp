#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
  int n;
  fin >> n;

  function<int(int, int)> euclid = [&](int x, int y)
  {
    if (y == 0)
      return x;

    return euclid(y, x % y);
  };

  for (int i = 1; i <= n; i++)
  {
    int x, y;
    fin >> x >> y;

    fout << euclid(x, y) << "\n";
  }

  return 0;
}