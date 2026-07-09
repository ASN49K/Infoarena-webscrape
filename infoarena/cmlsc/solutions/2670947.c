#include <stdio.h>

#define MAXN 1024

int a[MAXN];
int b[MAXN];
int max[1 + MAXN][1 + MAXN];// bordam cu 0 cand i = 0 sau j = 0
int com[MAXN];

int main(){
  FILE *fin  = fopen("cmlsc.in",  "r");
  FILE *fout = fopen("cmlsc.out", "w");

  int n, m, i, j, k, ncom;

  fscanf(fin, "%d%d", &n, &m);
  for( i = 0 ; i < n ; i++ )
    fscanf(fin, "%d", &a[i]);
  for( j = 0 ; j < m ; j++ )
    fscanf(fin, "%d", &b[j]);

  for( i = 1 ; i <= n ; i++ ){
    for( j = 1 ; j <= m ; j++ ){
      if( a[i - 1] == b[j - 1] )
        max[i][j] = max[i - 1][j - 1] + 1;
      else
        max[i][j] = max[i - 1][j] > max[i][j - 1] ? max[i - 1][j] : max[i][j - 1];
    }
  }

  fprintf(fout, "%d\n", ncom = max[n][m]);
  i = n;
  j = m;
  k = ncom - 1;
  while( k >= 0 ){
    if( a[i - 1] == b[j - 1] ){
      com[k--] = a[i - 1];
      i--;
      j--;
    }else if( max[i][j] == max[i - 1][j] )
      i--;
    else
      j--;
  }

  for( i = 0 ; i < ncom ; i++ )
    fprintf(fout, "%d ", com[i]);
  fputc('\n', fout);

  fclose(fin);
  fclose(fout);
  return 0;
}
