#include <fstream>

using namespace std;

int main() {
  ifstream cin("nim.in");
  ofstream cout("nim.out");
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unsigned a = 0, b;
    while (n--) {
      cin >> b;
      a ^= b;
    }
    cout << (a ? "DA\n" : "NU\n");
  }
  cin.close();
  cout.close();
  return 0;
}