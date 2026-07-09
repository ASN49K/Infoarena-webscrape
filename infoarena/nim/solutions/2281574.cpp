#include <bits/stdc++.h>

using namespace std;

int n, t, x, sum;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int main()
{
  fin >> t;
  while (t--) {
    fin >> n;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        fin >> x;
        sum ^= x;
    }
    if (sum != 0)
    fout << "DA\n";
    else
    fout << "NU\n";
  }
  return 0;
}
