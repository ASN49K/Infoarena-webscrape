#include <fstream>
std::ifstream inFile("euclid2.in");
std::ofstream outFile("euclid2.out");
int euclide(int a, int b) {
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  int numar, x, y;
  inFile >> numar;
  for (int i = 1; i <= n; ++i) {
    inFile >> x >> y;
    outFile << euclide(x, y) << "\n";
  }
  inFile.close();
  outFile.close();
  return 0;
}
