#include <bits/stdc++.h>

using namespace std;

ifstream fin( "euclid2.in" );
ofstream fout( "euclid2.out" );

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, r, a, b;

  fin >> t;
  while ( t-- ) {
	fin >> a >> b;
	while ( b ) {
	  r = a % b;
	  a = b;
	  b = r;
	}
    fout << a << "\n";
  }
  fin.close();
  fout.close();
  return 0;
}
