#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int NMAX = 1025;

int n, A[NMAX], m, B[NMAX];
int DP[NMAX][NMAX];

void read() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &A[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d", &B[i]);
}

void recons(int n, int m, vector<int>& res) {
  if (n == 0 || m == 0) return;
  
  if (A[n] == B[m]) {
    res.push_back(A[n]);
    recons(n - 1, m - 1, res);
  } else {
    if (DP[n - 1][m] > DP[n][m - 1]) {
      recons(n - 1, m, res);
    } else {
      recons(n, m - 1, res);
    }
  }
}

void longestCommonSubseq(int n, int A[], int m, int B[]) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
      if (A[i] == B[j]) {
        DP[i][j] = 1 + DP[i - 1][j - 1];
      }
    }
  
  printf("%d\n", DP[n][m]);
  
  vector <int> res;
  recons(n, m, res);
  reverse(res.begin(), res.end());
  for (size_t i = 0; i < res.size(); i++) {
    if (i > 0) printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
}

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  
  read();
  longestCommonSubseq(n, A, m, B);
  return 0;
}
