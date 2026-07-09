#include <fstream>
#include <iostream>

using namespace std;

int euclid(int a, int b) {
  while (b) {
    int c = a % b;

    a = b;
    b = c;
  }

  return a;
}

int main() {
  int a, b, n;

  ifstream cin("euclid2.in");
  ofstream cout("euclid2.out");
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    cout << euclid(a, b) << "\n";
  }
}
