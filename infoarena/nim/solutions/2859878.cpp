#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main(){
  int t, n, x, a;
  fin >> t;
  while (t--){
    fin >> n;
    x = 0;
    while (n--){
      fin >> a;
      x ^= a;
    }
    if (x)
      fout << "DA\n";
    else
      fout << "NU\n";
  }
  return 0;
}
