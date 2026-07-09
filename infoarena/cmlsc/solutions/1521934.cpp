#include <cstdio>

#define MAX 1030

using namespace std;

int a[MAX][MAX], v1[MAX], v2[MAX], sol[MAX];
int N, M;

void process() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (v1[i] == v2[j]) {
        a[i][j] = a[i - 1][j - 1] + 1;
      }
      if (a[i - 1][j] > a[i][j]) {
        a[i][j] = a[i - 1][j];
      }
      if (a[i][j - 1] > a[i][j]) {
        a[i][j] = a[i][j - 1];
      }
    }
  }
}

void getSolution() {
  int i = N;
  int j = M;
  int k = a[i][j];
  printf("%d\n", a[i][j]);
  while (i > 0 && j > 0) {
    if (v1[i] == v2[j]) {
      sol[k] = v1[i];
      k--;
      i--;
      j--;
    } else if (a[i][j] == a[i - 1][j]) {
      i--;
    } else {
      j--;
    }
  }
}

void printSol() {
  for (int i = 1; i <= a[N][M]; i++) {
    printf("%d ", sol[i]);
  }
}

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  scanf("%d %d\n", &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &v1[i]);
  }
  for (int j = 1; j <= M; j++) {
    scanf("%d", &v2[j]);
  }
  process();
  getSolution();
  printSol();
  return 0;
}
