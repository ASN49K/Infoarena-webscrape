#include <fstream>

using namespace std;

int gcd(int a,int b) { 
  return !b ? a : gcd(b, a % b);
}

int main() {
  ifstream cin("euclid2.in");
  ofstream cout("euclid2.out");
  int T, a, b;
  cin >> T;
  while (T--) {
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
  }
}
