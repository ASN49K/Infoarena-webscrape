#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
  int r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  int T, a, b;
  fin >> T;
  while (T) {
    fin >> a >> b;
    fout << euclid(a, b) << endl;
    T--;
  }
}