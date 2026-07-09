#include <array>
#include <fstream>
#include <algorithm>
#include <iterator>
 
 
const int NMAX = 1031;
 
template<typename T>
using sequence=std::array<T, NMAX>;
 
int main() {
    std::ifstream in{"cmlsc.in"};
    std::ofstream out{"cmlsc.out"};
 
    std::array<sequence<int>, 3> v;
    sequence<sequence<int>> dp;
 
    in >> v[0][0] >> v[1][0];
    for (int i = 1; i <= v[0][0]; ++i) in >> v[0][i];
    for (int i = 1; i <= v[1][0]; ++i) in >> v[1][i];
 
    for (int i = 1; i <= v[0][0]; ++i) {
        for (int j = 1; j <= v[1][0]; ++j) {
            if (v[0][i] == v[1][j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
 
    v[2][0] = dp[v[0][0]][v[1][0]];
    for (int i = v[0][0], j = v[1][0], k = v[2][0]; k; ) {
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
 
    std::copy(v[2].begin(), v[2].begin() + v[2][0] + 1, std::ostream_iterator<int>{out, " "});
    out << "\n";
 
 
    in.close();
    out.close();
 
    return 0;
}
