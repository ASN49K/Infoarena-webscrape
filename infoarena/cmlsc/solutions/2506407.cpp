#include <iostream>
#include <vector>

using namespace std;

int N, M, A[1200], B[1200], DP[1200][1200];
vector<int> result;

int main()
{
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  
  scanf("%d%d", &N, &M);

  for (int i = 1; i <= N; ++i)
    scanf("%d", &A[i]);
  for (int i = 1; i <= M; ++i)
    scanf("%d", &B[i]);

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (A[i] == B[j]) {
	DP[i][j] = DP[i-1][j-1] + 1;
      }
      else {
	DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
      }
    }
  }

  printf("%d\n", DP[N][M]);

  int i = N, j = M, pz = DP[N][M];
  while (i >= 0 && j >= 0) {
    if (A[i] == B[j]) {
      result.emplace_back(A[i]);
      --i;
      --j;
    }
    else {
      if (DP[i][j-1] > DP[i-1][j]) {
	--j;
      }
      else {
	--i;
      }
    }
  }

  for (int i = DP[N][M] - 1; i >= 0; --i)
    printf("%d ", result[i]);
  
  return 0;
}
