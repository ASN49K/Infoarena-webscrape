#include <fstream>
#include <array>
#include <iterator>
#include <algorithm>

const int NMAX = 1031;
using String = std::array<short, NMAX>;

int main() {
    String v, w, sol;
    std::array<String, NMAX> dp;
    std::ifstream in{"cmlsc.in"};
    std::ofstream out{"cmlsc.out"};

    in >> v[0] >> w[0];
    for (int i = 1; i <= v[0]; ++i) in >> v[i];
    for (int i = 1; i <= w[0]; ++i) in >> w[i];

    for (int i = 1; i <= v[0]; ++i) {
        for (int j = 1; j <= w[0]; ++j) {
            if (v[i] == w[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    sol[0] = dp[v[0]][w[0]];
    for (int i = v[0], j = w[0], k = sol[0]; i && j;) {
        if (v[i] == w[j]) {
          sol[k--] = v[i--];
          --j;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    std::copy(sol.begin(), sol.begin() + sol[0] + 1, std::ostream_iterator<int>{out, " "});
    return 0;
}

