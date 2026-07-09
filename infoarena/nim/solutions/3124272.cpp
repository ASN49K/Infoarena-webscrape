// https://infoarena.ro/problema/nim
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
  int t;
  fin>>t;

  while (t--) {
    int n, x;
    fin>>n;

    int s=0;
    for (int i=0; i<n; ++i) {
      fin>>x;
      s ^= x;
    }
    fout<<(s?"DA":"NU")<<endl;
  }
}