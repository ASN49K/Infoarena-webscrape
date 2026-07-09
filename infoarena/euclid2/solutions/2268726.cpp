
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
  if (b == 0) {
    return a;
  }
  return cmmdc(b, a % b);
}

int main() {
  int T, a, b;
  fin >> T;
  while (T--) {
    fin >> a >> b;
    fout << cmmdc(a, b) << '\n';
  }
  return 0;
}
