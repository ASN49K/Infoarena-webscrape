#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(b==0) return a;
    return cmmdc(b,a%b);
}

int main()
{
  int t, n, a, b;

  fin >> t;
  for(; n > 0; n--)
  {
      fin >> a >> b;
      fout << cmmdc(a,b) << "\n";
  }
}
