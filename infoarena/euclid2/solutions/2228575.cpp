#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd2(int a, int b) {
  if(0 < b)
    return gcd2(b, a % b);
  else
    return a;
}


int main() {

  int t, a, b;
  in >> t;
  for(int i = 0; i < t; i++) {
    in >> a >> b;
    out << gcd2(a, b) << "\n";
  }
  return 0;
}
