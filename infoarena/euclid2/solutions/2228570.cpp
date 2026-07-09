#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a, int b) {
  while(b > 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {

  int t, a, b;
  in >> t;
  for(int i = 0; i < t; i++) {
    in >> a >> b;
    out << gcd(a, b) << "\n";
  }
  return 0;
}
