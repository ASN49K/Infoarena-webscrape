#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file_in ("nim.in");
    ofstream file_out ("nim.out");

    int t, n, nr;
    int i;
    int sumXor;

    file_in >> t;
    for (; t > 0; t--) {
      sumXor = 0;
      file_in >> n;
      for (i = 0; i < n; i++) {
        file_in >> nr;
        sumXor ^= nr;
      }

      if (sumXor == 0) {
        file_out << "NU\n";
      } else {
        file_out << "DA\n";
      }
    }

    return 0;
}
