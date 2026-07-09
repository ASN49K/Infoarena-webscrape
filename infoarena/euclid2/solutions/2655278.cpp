#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main() {
  int n, a, b;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    while (a) {
      int r = b % a;
      b = a;
      a = r;
    }
    cout << b << endl;
  }
  return 0;
}