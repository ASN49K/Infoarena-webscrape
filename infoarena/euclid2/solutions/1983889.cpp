#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int maxDivizorComun(int numA, int numB) {
  if (numB == 0) {
    return numA;
  }

  return maxDivizorComun(numB, numA % numB);
}

int main() {
  int T;

  in >> T;

  for (int i = 1; i <= T; i++) {
    int numA;
    int numB;

    in >> numA;
    in >> numB;
    out << maxDivizorComun(numA, numB) << "\n";
  }

  return 0;
}
