#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(unsigned long long a, unsigned long long b) {

  unsigned long long r ;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}
int main() {

  int T;
  unsigned long long a, b;
  fin >> T;
  for (int i = 0; i < T; i++) {
    fin >> a >> b;
    fout << euclid(a, b) << "\n";
  }

  return 0;
}
