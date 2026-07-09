#include <fstream>

int main() {
  std::ifstream fin("nim.in");
  std::ofstream fout("nim.out");
  int t;
  fin >> t;
  while (t--) {
    int n;
    fin >> n;
    int XOR = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      fin >> x;
      XOR ^= x;
    }
    if (XOR == 0) {
      fout << "NU\n";
    } else {
      fout << "DA\n";
    }
  }
  return 0;
}
