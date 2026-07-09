#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int t, a, b, r = 0, aux = 0;
    fin >> t;
    for(int i = 1; i <= t; i++)
    {
      fin >> a >> b;
      if( a > b )
      {
          aux = a;
          a = b;
          b = aux;
      }
      r = 0;
      while(b)
      {
          r = a % b;
          a = b;
          b = r;
      }
      fout << a <<" ";
    }
}
