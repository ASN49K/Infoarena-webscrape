#include <array>
#include <fstream>
#include <iterator>
#include <algorithm>

constexpr int N_MAX = 1031;

int main() {
    std::ifstream in{"cmlsc.in"};
    std::ofstream out{"cmlsc.out"};

    int N, M;
    std::array<int, N_MAX> v;
    std::array<int, N_MAX> w;
    std::array<std::array<int, N_MAX>, N_MAX> dp;

    in >> N >> M;
    
    for (int i = 0; i < N; ++i) in >> v[i];
    for (int j = 0; j < M; ++j) in >> w[j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i] == w[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int k = dp[N - 1][M - 1];
    std::array<int, N_MAX> sol;

    for (int i = N - 1, j = M - 1; i >= 0 && j >= 0; ) {
        if (v[i] == w[j]) {
            sol[--k] = v[i];
            --i, --j;
        }
        else if (dp[i][j - 1] >= dp[i - 1][j]) --j;
        else --i;
    }
    
    out << dp[N - 1][M - 1] << '\n';
    copy(sol.begin(), sol.begin() + dp[N - 1][M - 1], std::ostream_iterator<int>{out, " "});
    out << '\n';


    in.close();
    out.close();

    return 0;
}
