#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v1[1050], v2[1050], sir[1050], dp[1050][1050];
int main()
{
   fin >> n >> m;
   for (int i = 1; i <= n; ++i)
      fin >> v1[i];

   for (int i = 1; i <= m; ++i)
      fin >> v2[i];

   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         if (v1[i] == v2[j])
            dp[i][j] = dp[i - 1][j - 1] + 1;
         else
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
   }

   int i = n, j = m;
   while (i && j) {
      if (v1[i] == v2[j]) {
         sir[dp[i][j]] = v1[i];
         --i;
         --j;
      }
      else if (dp[i][j - 1] > dp[i - 1][j])
         --j;
      else
         --i;
   }

   fout << dp[n][m] << '\n';
   for (int i = 1; i <= dp[n][m]; ++i)
      fout << sir[i] << ' ';
   return 0;
}
