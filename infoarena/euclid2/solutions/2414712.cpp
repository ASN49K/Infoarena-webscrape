/**
 * @Author: catalin
 * @Date:   24-Apr-2019
 * @Last modified by:   catalin
 * @Last modified time: 24-Apr-2019
 */
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main() {
  int t, x, y;
  fin >> t;
  for (int i = 0; i < t; ++i) {
    fin >> x >> y;
    while (y) {
      int r = x % y;
      x = y;
      y = r;
    }
    fout << x << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}
