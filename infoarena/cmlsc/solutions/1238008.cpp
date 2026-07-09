#include <array>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;
const int NMAX = 1031;
using String = array<int, NMAX>;


int main() {
  array<String, 3> strings;
  array<String, NMAX> dp;

  ifstream in {"cmlsc.in"};

  in >> strings[0][0] >> strings[1][0];
  for (size_t i = 0; i < 2; ++i) {
    for (int j = 1; j <= strings[i][0]; ++j) {
      in >> strings[i][j];
    }
  }

  for (int i = 1; i <= strings[0][0]; ++i) {
    for (int j = 1; j <= strings[1][0]; ++j) {
      if (strings[0][i] == strings[1][j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  strings[2][0] = dp[strings[0][0]][strings[1][0]];
  for (int i = strings[0][0], j = strings[1][0], k = strings[2][0]; i && j; ) {
    if (strings[0][i] == strings[1][j]) {
      strings[2][k--] = strings[0][i--];
      --j;
    }
    else if (dp[i - 1][j] >= dp[i][j - 1]) {
      --i;
    }
    else {
      --j;
    }
  }

  ofstream out{"cmlsc.out"};

  out << strings[2][0] << '\n';
  copy(strings[2].begin() + 1, 
       strings[2].begin() + strings[2][0] + 1, 
       ostream_iterator<int>{out, " "}
      );

  return EXIT_SUCCESS;
}

