#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, x, s;

int main() {
  fin.tie(0);
  fout.tie(0);

  fin >> t;
  while(t--) {
    fin >> n;

    s = 0;
    for(int i = 1; i <= n; i++) {
      fin >> x;
      s ^= x;
    }

    if(!s)
      fout << "NU\n";
    else fout << "DA\n";

  }

  return 0;
}