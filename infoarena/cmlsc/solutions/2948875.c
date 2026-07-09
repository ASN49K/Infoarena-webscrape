#include <stdio.h>
#include <stdint.h>

void read_uint32_t(FILE *__restrict stream, uint32_t *__restrict nr) {
  uint8_t ch;
  *nr = 0;
  while ((ch = fgetc(stream)) && ('0' <= ch && ch <= '9')) {
    *nr *= 10;
    *nr += ch - '0';
  }
  if (ch == '\r') {
    fgetc(stream);
  }
}
uint32_t __inline__ __attribute((pure)) max(uint32_t o1, uint32_t o2) {
  return o1 > o2 ? o1 : o2;
}

uint32_t a[1025];
uint32_t b[1025];
uint32_t dp[1025][1025];
uint32_t n, m;

void pout(FILE *__restrict out, uint32_t i, uint32_t j) {
  if (i == 0 || j == 0) {
    return;
  }
  if (a[i] == b[j]) {
    pout(out, i - 1, j - 1);
    fprintf(out, "%u ", a[i]);
    return;
  }
  if (dp[i - 1][j] > dp[i][j - 1]) {
    pout(out, i - 1, j);
  } else {
    pout(out, i, j - 1);
  }
}

int main(void) {
  {
    FILE *__restrict in = fopen("cmlsc.in", "r");
  
    read_uint32_t(in, &n);
    read_uint32_t(in, &m);
    {
      int32_t i;
      for(i = 1; i <= n; ++i) {
        read_uint32_t(in, a + i);
      }
      for(i = 1; i <= m; ++i) {
        read_uint32_t(in, b + i);
      }
    }
  
    fclose(in);
  }

  {
    int32_t i, j;
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= m; ++j) {
        if (a[i] == b[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
  }

  {
    FILE *__restrict out = fopen("cmlsc.out", "w");
  
    fprintf(out, "%u\n", dp[n][m]);
    pout(out, n, m);
  
    fclose(out);
  }

  return 0;
}
