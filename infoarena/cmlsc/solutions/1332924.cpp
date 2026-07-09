#include <array>
#include <fstream>
#include <cstdlib>
#include <iterator>

using namespace std;
const int NMAX = 1031;
using String = array<int, NMAX>;


int main() {
  array<String, 3> v;
  array<String, NMAX> dp;
  ifstream in{"cmlsc.in"};
  ofstream out{"cmlsc.out"};

  in >> v[0][0] >> v[1][0];
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= v[i][0]; ++j) {
      in >> v[i][j];
    }
  }

  for (int i = 1; i <= v[0][0]; ++i) {
    for (int j = 1; j <= v[1][0]; ++j) {
      if (v[0][i] == v[1][j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  v[2][0] = dp[v[0][0]][v[1][0]];
  for (int i = v[0][0], j = v[1][0], k = v[2][0]; i && j; ) {
    if (v[0][i] == v[1][j]) {
      v[2][k--] = v[0][i--];
      --j;
    }
    else if (dp[i - 1][j] > dp[i][j - 1]) {
      --i;
    }
    else {
      --j;
    }
  }

  out << v[2][0] << '\n';
  copy(v[2].begin() + 1, v[2].begin() + v[2][0] + 1, ostream_iterator<int>{out, " "});
  out << '\n';

  return EXIT_SUCCESS;
}
