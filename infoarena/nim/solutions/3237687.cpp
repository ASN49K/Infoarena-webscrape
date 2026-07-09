#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin( "nim.in" );
ofstream fout( "nim.out" );

int main() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  int t, n, s, x;

  fin >> t;
  while ( t-- ) {
	fin >> n;
	s = 0;
	for ( int i = 1; i <= n; ++i ) {
      fin >> x;
	  s ^= x;
	}
	fout << (s == 0 ? "NU\n" : "DA\n");
  }
  fin.close();
  fout.close();
  return 0;
}

