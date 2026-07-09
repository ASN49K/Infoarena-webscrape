#include <bits/stdc++.h>
using namespace std;

ifstream fin( "nim.in" );
ofstream fout( "nim.out" );

void solve() {
  int n, i, a, xor_sum;
  xor_sum = 0;
  fin >> n;
  for( i = 0; i < n; i++ ) {
    fin >> a;
    xor_sum = xor_sum ^ a;
  }
  if( xor_sum == 0 )
    fout << "NU\n";
  else
    fout << "DA\n";
}
int main() {
  int t;
  fin >> t;
  while( t-- ) {
    solve();
  }
  return 0;
}
