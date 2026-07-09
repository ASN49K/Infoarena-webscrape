/**
 * 001 Cel mai lung subsir comun (LCS)
 * -----------------------------------
 * Mihai Cirlanaru
*/

#include <stdio.h>
#include <stdlib.h>

int max (int a, int b) {
  if (a < b) return b;
  return a;
}

void fprintLCS (FILE* f, int** C, int* A, int* B, int i, int j) {
  if (i == 0 || j == 0) {
  
  } else {
    if (A[i] == B[j]) {
      fprintLCS (f, C, A, B, i-1, j-1);
      fprintf(f, "%d ", A[i]);
    } else {
      if (C[i][j-1] > C[i-1][j])
	fprintLCS(f, C, A, B, i, j-1);
      else
	fprintLCS(f, C, A, B, i-1, j);
    }
  }
}

int main () {
  int M, N;
  int *A, *B, **suffix, i, j, maxLength = 0;
  
  FILE *in, *out;
  in = fopen("cmlsc.in", "r");
  if (!in) {
    fprintf(stderr, "Error opening input file!\n");
    return 1;
  }
  
  out = fopen("cmlsc.out", "w");
  if (!out) {
    fprintf(stderr, "Error opening output file!\n");
    return 1;
  }
  
  fscanf(in, "%d %d", &M, &N);
  
  A = (int*)malloc((M+1)*sizeof(int));
  if (!A) {
    fprintf(stderr, "Error Allocating memory!\n");
    return 1;
  }
  
  B = (int*)malloc((N+1)*sizeof(int));
  if (!B) {
    fprintf(stderr, "Error Allocating memory!\n");
    return 1;
  }
  
  suffix = (int **)malloc((M+1)*sizeof(int *));
  if (!suffix) {
    fprintf(stderr, "Error Allocating memory!\n");
    return 1;
  }
  
  for (i = 0; i <= M; i++) {
    suffix[i] = (int *)malloc((N+1)*sizeof(int));
    if(!suffix[i]) {
      fprintf(stderr, "Error Allocating memory!\n");
      return 1;
    }
    
    for (j = 0; j <= N; j++)
      suffix[i][j] = 0;
  }
  
  for (i = 1; i <= M; i++)
    fscanf(in, "%d", &A[i]);
  
  for (i = 1; i <= N; i++)
    fscanf(in, "%d", &B[i]);
  
  /* Longest Common Subsequence Algorithm */
  
  for (i = 0; i <= M; i++)
    suffix[i][0] = 0;
  
  for (i = 0; i <= N; i++)
    suffix[0][i] = 0;
    
  for (i = 1; i <= M; i++)
    for (j = 1; j <= N; j++)
      if (A[i] == B[j]) {
	suffix[i][j] = suffix[i-1][j-1] + 1;
      } else {
	suffix[i][j] = max(suffix[i][j-1], suffix[i-1][j]);
      }
  
  maxLength = suffix[M][N];
  fprintf(out, "%d\n", maxLength);
  
  /*/
  printf("Max: %d\n", maxLength);
  
  for (i = 0; i <= M; i++) {
    for (j = 0; j <= N; j++)
      printf("%d ", suffix[i][j]);
    printf("\n");
  }
  //*/
  fprintLCS(out, suffix, A, B, M, N);
  fprintf(out, "\n");
  
  /* Free the memory */
  for (i = 0; i <= M; i++)
    free(suffix[i]);
  
  free(suffix);
  free(A);
  free(B);
  /* Close the files */
  fclose(in);
  fclose(out);
  return 0;
}
