#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> A, B;
std::vector<std::vector<int>> DP;
int N, M;

void read()
{
  scanf("%d%d", &N,&M);
  A.resize(N + 1);
  B.resize(M + 1);
  DP.resize(N + 1, std::vector<int>(M + 1, 0));
  for (int i = 1; i <= N; ++i)
    scanf("%d", &A[i]);
  for (int i = 1; i <= M; ++i)
    scanf("%d", &B[i]);
}

void computeLongest()
{
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      if (A[i] == B[j]) // match
	DP[i][j] = std::max(DP[i][j], DP[i-1][j-1] + 1);
      else
	DP[i][j] = std::max(DP[i][j], std::max(DP[i-1][j], DP[i][j-1]));
  int best = DP[N][M];
  printf("%d\n", best);
  
  std::vector<int> ans;
  int i = N, j = M;
  while (best) {
    if (A[i] == B[j]) {
      ans.emplace_back(A[i]);
      --i; --j;
      --best; // found one match
      continue;
    }
    if (DP[i][j] == DP[i-1][j])
      --i;
    else
      --j;
  }
  reverse(ans.begin(), ans.end());
  for (auto it: ans)
    printf("%d ", it);
}

int main()
{
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  read();
  computeLongest();
  
  return 0;
}
