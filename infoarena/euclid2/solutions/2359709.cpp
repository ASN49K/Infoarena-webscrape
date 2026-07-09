#include <fstream>
#include <iostream>

int gcd(int left, int right) {
  return (!right) ? left : gcd(right, left % right);
}

int main() {
  std::ifstream input("euclid2.in");
  std::ofstream output("euclid2.out");
  int n;
  input >> n;
  for (int index = 0; index < n; index++) {
    int left, right;
    input >> left >> right;
    output << gcd(left, right) << '\n';
  }
  output.close();
  input.close();
  return 0;
}
