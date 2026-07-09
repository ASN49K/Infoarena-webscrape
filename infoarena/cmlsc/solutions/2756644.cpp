#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> DP;
vector<int> A, B;
int N, M;

int main()
{
  freopen("cmlsc.in", "r" ,stdin);
  freopen("cmlsc.out", "w", stdout);

  scanf("%d%d", &N, &M);
  A.resize(N+1);
  B.resize(M+1);
  DP.resize(N + 1, vector<int>(M + 1));
  for (int i = 1; i <= N; ++i)
    scanf("%d", &A[i]);
  for (int i = 1; i <= M; ++i)
    scanf("%d", &B[i]);

  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
      if (A[i] == B[j])
	DP[i][j] = max(DP[i-1][j-1] + 1, DP[i][j]);
    }
  printf("%d\n", DP[N][M]);

  vector<int> ans;
  while (N && M) {
    if (A[N] == B[M]) {
      ans.emplace_back(A[N]);
      --N;
      --M;
      continue;
    }

    if (DP[N][M-1] > DP[N-1][M])
      --M;
    else
      --N;
  }
  reverse(ans.begin(), ans.end());
  for (auto it: ans)
    printf("%d ", it);
  return 0;
}
