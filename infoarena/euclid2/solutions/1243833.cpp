#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int x, int y) {
  int remainder = x % y;
  if (!remainder) {
    return y;
  }
  return cmmdc(y, remainder);
}

int main (int argc, char const *argv[]) {
  int nr, x, y;
  in>>nr;
  for(int i = 0; i < nr; ++i) {
    in>>x>>y;
    out<<cmmdc(x, y)<<"\n";
  }
  return 0;
}
