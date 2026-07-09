#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b) {
  int aux;
  while (b != 0) {
    aux = a % b;
    a = b;
    b = aux;
  }
  return a;
}

int main() {
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");

  int n, a, b;
  fin >> n;
  for (int i = 0; i < n; ++i) {
    fin >> a >> b;
    fout << euclid(a, b) << endl;
  }

  return 0;
}
