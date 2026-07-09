#include <array>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;

const int NMAX = 1031;
using String = array<int, NMAX>;
using Matrix = array<array<int, NMAX>, NMAX>;

void read(array<String, 3>& v) {
  ifstream in {"cmlsc.in"};

  in >> v[0][0] >> v[1][0];  
  for (int i = 0; i < 2; ++i) {
     for (int j = 1; j <= v[i][0]; ++j) {
        in >> v[i][j];
     }
  }
}

void solve(array<String, 3>& v) {
  Matrix dp;

  for (int i = 1; i <= v[0][0]; ++i) {
     for (int j = 1; j <= v[1][0]; ++j) {
        if (v[0][i] == v[1][j]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
     }
  }

  for (int i = v[0][0], j = v[1][0], k = v[2][0] = dp[i][j]; i && j; ) {
     if (v[0][i] == v[1][j]) {
       v[2][k--] = v[0][i--];
       --j;
     }
     else if (dp[i - 1][j] >= dp[i][j - 1]) {
       --i;
     }
     else {
       --j;
     }
  }
}

void output(const String& v) {
  ofstream out {"cmlsc.out"};

  out << v[0] << '\n';
  copy(v.begin() + 1, v.begin() + v[0] + 1, ostream_iterator<int>{out, " "});
  out << '\n';
}

int main() {
  array<String, 3> v;

  read(v);
  solve(v);
  output(v[2]);

  return EXIT_SUCCESS;
}
