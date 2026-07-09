#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned int T;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}

int main() {
  fin >> T;
  while (T--) {
    unsigned long long a, b;
    fin >> a >> b;
    fout << gcd(a, b) << '\n';
  }
  return 0;
}