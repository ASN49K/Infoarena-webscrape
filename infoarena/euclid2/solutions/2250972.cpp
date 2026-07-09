#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

// This function take two integers a and b
// and returns their greatest common divisor (gcd)
// gcd(a, 0) = 0
// gcd(a, b) = gcd(b, a % b)
int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n, a, b;
  fin >> n;
  for (int i=1; i<=n; i++){
    fin >> a >> b;
    int d = gcd(a, b);
    fout << d << '\n';
  }
  return 0;
}
