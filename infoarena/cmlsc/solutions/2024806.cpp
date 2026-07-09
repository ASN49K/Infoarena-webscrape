#include <array>
#include <fstream>

constexpr int NMAX = 1031;

using str = std::array<int, NMAX>;

std::array<str, NMAX> dp; 

int main() {
   std::array<str, 3> v;
   std::ifstream in{"cmlsc.in"};
   std::ofstream out{"cmlsc.out"};

   in >> v[0][0] >> v[1][0];

   for (int i = 0; i < 2; ++i) {
      for (int j =  1; j <= v[i][0]; ++j) in >> v[i][j];
   }

   for (int i = 1; i <= v[0][0]; ++i) {
      for (int j = 1; j <= v[1][0]; ++j) {
         if (v[0][i] == v[1][j]) dp[i][j] = 1 + dp[i - 1][j - 1];
         else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
   }

   v[2][0] = dp[v[0][0]][v[1][0]];
   for (int i = v[0][0], j = v[1][0], k = v[2][0]; i && j; ) {
      if (v[0][i] == v[1][j]) {
        v[2][k] = v[0][i];
        --k, --i, --j;
      }
      else if (dp[i - 1][j] > dp[i][j - 1]) --i;
      else --j;
   }

   out << v[2][0] << '\n';
   for (int i = 1; i <= v[2][0]; ++i) out << v[2][i] << ' ';

   return 0;
}
