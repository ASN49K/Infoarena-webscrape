#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned int T;

int main() {
  fin >> T;
  while (T--) {
    unsigned long long a, b;
    fin >> a >> b;
    while (a != b) {
      if (a > b)
        a -= b;
      else
        b -= a;
    }

    fout << a << '\n';
  }
  return 0;
}