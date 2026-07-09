#define maxs(a, b) a = (a > b) ? a : b
#define mins(a, b) a = (a < b) ? a : b

#define all(a) a.begin(), a.end()
#define rng(a, i, j) a.begin() + i, a.begin() + j

#define aall(a, n) a + 1, a + 1 + n
#define arng(a, i, j) a + i, a + j

#define pb push_back
#define ins insert
#define sz(a) (int)a.size()

#define rs inFile
#define ws outFile

#include <fstream>
#include <iostream>

// recursive form
int euclid_gcd(int a, int b) {
  if (!b) {
    return a;
  }

  return euclid_gcd(b, a % b);
}

int main() {
  std::ifstream inFile("euclid2.in");
  std::ofstream outFile("euclid2.out");

  int tests;
  rs >> tests;

  while (tests--) {
    int a, b;
    rs >> a >> b;

    ws << euclid_gcd(a, b) << '\n';
  }

  return 0;
}