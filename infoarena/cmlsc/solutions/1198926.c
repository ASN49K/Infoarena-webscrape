#include <stdio.h>
#include <stdlib.h>

int n, m;
int *v1, *v2;

void readData(){
	int i;
  FILE* in = fopen("cmlsc.in", "r");
	fscanf(in, "%d%d", &n, &m);

	v1 = (int*)malloc(n * sizeof(int));
	v2 = (int*)malloc(m * sizeof(int));
  for (i = 0; i < n; i++) {
    fscanf(in, "%d",  &v1[i]);
  }
  for (i = 0; i < m; i++) {
    fscanf(in, "%d",  &v2[i]);
  }
  fclose(in);
}

int max(int x, int y) {
  return x > y ? x : y;
}

void solve(){
	int** dp;
	int i, j, aux;
	dp = (int**)malloc((n+1) * sizeof(int*));
	for (i = 0; i <= n; i++) {
		dp[i] = (int*)calloc((m+1), sizeof(int));
	}
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      if (v1[i-1] == v2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  FILE* out = fopen("cmlsc.out", "w");
  i = 0, j = 0;
  fprintf(out,"%d\n",dp[n][m]);

  i = n, j = m;
  int solutions = dp[n][m] - 1;
  int* results = (int*)malloc(n*sizeof(int));

  while (dp[i][j]) {
    if (v1[i-1] == v2[j-1]) {
      results[solutions--]=v1[i-1];
      i--, j--;
      continue;
    }
    if (dp[i-1][j] == dp[i][j]) {
      i--;
    }
    else {
      j--;
    }
  }
  for (i = 0; i < dp[n][m]; ++i){
    fprintf(out, "%d ", results[i]);
  }

  for (i = 0; i <= n; ++i) {
    free(dp[i]);
  }
  free(dp);
  free(results);

  free(v1);
  free(v2);

  fclose(out);
}

int main(int argc, char** argv) {
	readData();
	solve();
	return 0;
}
