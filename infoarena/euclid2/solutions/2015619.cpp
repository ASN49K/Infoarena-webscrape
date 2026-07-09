#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int gcd(int a, int b) {
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int main() {
  int t;
  cin >> t;

  while (t --) {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
  }
}