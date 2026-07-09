#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int N, M, A[1025], B[1025], result[1025][1025];
stack <int> s;

void readArray(int A[], int length) {
  for (int i = 0; i < length; ++i) {
    scanf("%d", &A[i]);
  }
}

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  scanf("%d %d\n", &N, &M);

  readArray(A, N);
  readArray(B, M);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (A[i] == B[j]) {
        result[i+1][j+1] = result[i][j] + 1;
      } else {
        result[i+1][j+1] = max(result[i][j+1], result[i+1][j]);
      }
    }
  }

  // for (int i = 1; i <= N; ++i) {
  //   for (int j = 1; j <= M; ++j) {
  //     printf("%d ", result[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("%d\n", result[N][M]);

  for (int i = N, j = M; i;) {
    if (A[i-1] == B[j-1]) {
      s.push(A[i-1]);
      --i, --j;
    } else if (result[i-1][j] < result[i][j-1]) {
      --j;
    } else {
      --i;
    }
  }

  for (;!s.empty(); s.pop()) {
    printf("%d ", s.top());
  }

  return 0;
}
