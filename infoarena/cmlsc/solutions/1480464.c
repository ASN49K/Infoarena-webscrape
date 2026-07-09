#include <stdio.h>

#define Nadejde 1025

int N, M;
int s[Nadejde];
int p[Nadejde];
int d[Nadejde][Nadejde];   // lcs pentru "i" si "j".
int count, order[Nadejde]; // subsirul comun.

/** max(X, Y). **/
int MAX(int X, int Y) {
  return (X > Y) ? X : Y;
}

/** Algoritmul Lcs. **/
void lcs() {
  int i, j;
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) {
      if (s[i] == p[j]) {
        d[i][j] = d[i - 1][j - 1] + 1;
      } else {
        d[i][j] = MAX(d[i - 1][j], d[i][j - 1]);
      }
    }
  }
}

/** Reconstituirea subsirului. **/
void traceBack() {
  int i = N, j = M;
  while ((i > 0) && (j > 0)) {
    if (s[i] == p[j]) {
      order[++count] = s[i];
      i--, j--;
    } else {
      if (d[i - 1][j] > d[i][j - 1]) {
        i--;
      } else {
        j--;
      }
    }
  }
}

int main(void) {
  int i;
  FILE *f = fopen("cmlsc.in", "r");

  fscanf(f, "%d %d", &N, &M);
  for (i = 1; i <= N; i++) {
    fscanf(f, "%d", &s[i]);
  }
  for (i = 1; i <= M; i++) {
    fscanf(f, "%d", &p[i]);
  }
  fclose(f);

  f = fopen("cmlsc.out", "w");

  lcs();
  traceBack();

  fprintf(f, "%d\n", count);
  while (count) {
    fprintf(f, "%d ", order[count--]);
  }
  fputc('\n', f);
  fclose(f);

  /// Multumim Doamne!
  puts("Doamne ajuta!");
  return 0;
}
