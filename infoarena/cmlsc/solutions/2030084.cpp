#include <cstdio>

#define NMAX 1025

int n, m;
int v[NMAX], w[NMAX], path[NMAX][NMAX];

void read(int* v, int length) {
  for (int i = 1; i <= length; i++) {
    scanf("%d", &v[i]);
  }
}

void print(int* v, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void computeLongestSubstring() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i] == w[j]) {
        path[i][j] = path[i - 1][j - 1] + 1;
      } else if (path[i - 1][j] > path[i][j - 1]) {
        path[i][j] = path[i - 1][j];
      } else {
        path[i][j] = path[i][j - 1];
      }
    }
  }
}

void printSolution() {
  int i = n;
  int j = m;
  int k = 0;
  int solution[NMAX];
  while (i > 0 && j > 0) {
    if (v[i] == w[j]) {
      solution[k++] = v[i];
      i--;
      j--;
    } else if (path[i][j] == path[i - 1][j]) {
      i--;
    } else {
      j--;
    }
  }
  printf("%d\n", k);
  for (int i = k - 1; i >= 0; i--) {
    printf("%d ", solution[i]);
  }
}

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  scanf("%d %d", &n, &m);
  read(v, n);
  read(w, m);
  computeLongestSubstring();
  printSolution();
  return 0;
}
