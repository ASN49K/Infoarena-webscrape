#include <fstream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int main () {
  int d, i, r, p, j;

  fi >> p;
  for (j = 1; j <= p; j++) {
    fi >> d >> i;
    do {
      r = d % i; // Citim "d modulo i".
      d = i;
      i = r;
    } while (r > 0);
    fo << d << endl;
  }
  return 0;
}

//a = 28
//b = 6
//
//Algoritmul lui Euclid
// d  i  r
//---------
//28  6  4
// 6  4  2
// 4  2  0
// 2  0  0
