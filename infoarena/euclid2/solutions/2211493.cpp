#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n, a, b;

int main()
{
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a >> b;
    fout << __gcd(a, b) << "\n";
  }
  return 0;
}
