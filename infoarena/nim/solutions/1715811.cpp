#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int T, n, xorsum;

int main() {
  cin >> T;
  for (int task = 1; task <= T; ++task) {
    cin >> n;
    xorsum = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      xorsum ^= x;
    }

    if (xorsum) cout << "DA\n";
    else cout << "NU\n";
  }
  return 0;
}
