#include <fstream>
#include <iostream>
#include <string>

#define ll long long
#define ull unsigned long long
#define pii std::pair<int, int>

#define IO (std::string) "euclid2"
std::ifstream cin(IO + ".in");
std::ofstream cout(IO + ".out");

#define NMAX 100

int EuclidDiv(int a, int b) {
  if (!b)
    return a;
  return EuclidDiv(b, a % b);
}

int EuclidDif(int a, int b) {
  if (!b)
    return a;
  if (a > b)
    return EuclidDif(a - b, b);
  return EuclidDif(a, b - a);
}

int main() {
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << EuclidDiv(a, b) << '\n';
  }
  return 0;
}
