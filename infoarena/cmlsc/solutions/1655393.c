#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maximum(a, b) (((a) > (b)) ? (a) : (b))
#define NMax 1024

int main(void) {
  int M, N;
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w+", stdout);
  scanf("%d %d", &M, &N);

  int A[NMax] = {0}, B[NMax] = {0}, D[NMax][NMax] = {{0}};

  for(int i = 1; i <= M; i++) {
    scanf("%d", &A[i]);
  }
  for(int i = 1; i <= N; i++) {
    scanf("%d", &B[i]);
  }

  for(int i = 1; i <= M; i++) {
    for(int j = 1; j <= N; j++) {
      if(A[i] == B[j]) D[i][j] = 1 + D[i-1][j-1];
      else D[i][j] = maximum(D[i-1][j], D[i][j-1]);
    }
  }
  int res[NMax] = {0}, idx = 0;
  for(int i = M, j = N; i;) {
    if(A[i] == B[j]) res[++idx] = A[i], --i, --j;
    else if(D[i-1][j] < D[i][j-1]) --j;
         else --i;
  }

  printf("%d\n", idx);
  for(int i = idx; i; --i) {
    printf("%d ", res[i]);
  }

  return 0;
}
