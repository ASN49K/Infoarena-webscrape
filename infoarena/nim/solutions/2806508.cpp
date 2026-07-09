#include <bits/stdc++.h>

using namespace std;

ifstream fin( "nim.in" );
ofstream fout( "nim.out" );

int main() {
  int q, n, s, x, i;
  fin >> q;
  while( q-- ){
    fin >> n;
    s = 0;
    for( i = 1; i <= n; ++i ) {
      fin >> x;
      s ^= x;
    }
    if( s > 0 )
      fout << "DA";
    else
      fout << "NU";
    fout << "\n";
  }
  return 0;
}
