#include <cstdio>
#define IN_FILE_NAME "cmlsc.in"
#define OUT_FILE_NAME "cmlsc.out"
#define NMAX 1025
FILE *in, *out;
int NA, NB, NResult;
int A[NMAX], B[NMAX];
int result[NMAX];
char size[NMAX][NMAX];

int max(int a, int b) {
  return a > b ? a : b;
}

void readArray(int N, int A[]) {
  for(int i = 1 ; i <= N ; i++) {
    fscanf(in, "%d", &A[i]);
  }
}

void solve() {
  for(int i = 1 ; i <= NA ; i++) {
    for(int j = 1 ; j <= NB ; j++) {
      if( A[i] == B[j]) {
        size[i][j] = size[i-1][j-1] + 1;
      }
      size[i][j] = max(
          size[i][j],
          max(size[i][j-1], size[i-1][j])
        );
    }
  }
}

void generateResult() {
  int i, j;
  for (i = NA ,j = NB; i > 0 && j > 0; ) {
    if (A[i] == B[j]
     && size[i][j] == size[i-1][j-1] + 1) {
      result[NResult++] = A[i];
      i--;
      j--;
    } else if (size[i][j] == size[i-1][j]) {
      i--;
    } else if (size[i][j] == size[i][j-1]) {
      j--;
    }
  }
  NResult--;
}


int main() {
  in = fopen(IN_FILE_NAME, "r");
  out = fopen(OUT_FILE_NAME, "w");
  fscanf (in, "%d %d", &NA, &NB);
  readArray(NA, A);
  readArray(NB, B);
  solve();
  fprintf(out, "%d\n", size[NA][NB]);
  generateResult();
  for (; NResult >= 0; NResult--) {
    fprintf(out, "%d ", result[NResult]);
  }

  fclose(in);
  fclose(out);
  return 0;
}
