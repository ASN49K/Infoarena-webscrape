#include <fstream>
#include <vector>

int main() {
  int N, M;
  std::vector<int> v, w;
  std::vector<std::vector<int>> dp;
 

  std::ifstream in {"cmlsc.in"};

  in >> N >> M;
  v.reserve(N);
  for (int i = 0; i < N; ++i) {
     in >> v[i];
  }
  w.reserve(M);
  for (int j = 0; j < M; ++j) {
      in >> w[j];
  }

  dp.resize(N + 1);
  dp[0] = std::vector<int>(M + 1, 0);
  for (int i = 1; i <= N; ++i) {
     dp[i] =  std::vector<int>(M + 1, 0);
     for (int j = 1; j  <= M; ++j) {
         if (v[i - 1] == w[j - 1]) {
             dp[i][j] = dp[i - 1][j - 1] + 1;
         } else {
             dp[i][j] = std::max(dp[i][j-1], dp[i - 1][j]);
         }
     }
  }

  std::vector<int> match;
  int i = N, j = M, k = dp[N][M] - 1;
  match.reserve(k + 1);
  while (k >= 0) { 
     if (v[i - 1] == w[j - 1]) {
          match.emplace_back(v[i - 1]);
          --i, --j, --k;
     } else if (dp[i][j - 1] >= dp[i - 1][j]) {
         --j;
     } else {
         --i;
     }
  }

  std::ofstream out {"cmlsc.out"};
  out << dp[N][M] << '\n';
  for (auto it = match.rbegin(); it != match.rend(); ++it) {
    out << *it << ' ';
  }
  
  return 0;
}
