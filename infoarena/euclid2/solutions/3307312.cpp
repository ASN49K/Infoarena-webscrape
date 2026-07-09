#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int n, int m) {
  int r = 0;
  while (m) {
    r = n % m;
    n = m;
    m = r;
  }
  return n;
}

int main() {
  int n, a, b;
  fin >> n;
  while (n != 0) {
    fin >> a >> b;
    n--;
    fout << cmmdc(a, b)<<endl;
  }
}

/*
  https://www.infoarena.ro/problema/euclid2 <- ok
  https://www.infoarena.ro/problema/combinari
  https://www.infoarena.ro/problema/cautbin
*/