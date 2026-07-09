#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int CMMDC(int a, int b)
{
  int r = 0;
  while(b)
  {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main()
{
  int t, a, b;
  fin >> t;
  while(t--)
  {
    fin >> a >> b;
    fout << CMMDC(a, b) << "\n";
  }
  return 0;
}