#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int m, n, a[MAX+1], b[MAX+1];
short int lcs[MAX+1], c[MAX+1][MAX+1];

void citeste(int v[], int n, FILE *in) {
  int i;
  for ( i = 1; i <= n; i++ )
    fscanf(in, "%d", &v[i]);
}

int max(char a, char b) {
  return a > b ? a : b;
}

void longestCommonSubsequence() {
  int i, j;
  for ( i = 0; i <= m; i++ )
    c[i][0] = 0;
  for ( j = 0; j <= n; j++ )
    c[0][i] = 0;

  for ( i = m; i >= 1; i-- )
    for ( j = n; j >= 1; j-- )
      if ( a[i] == b[j] )
        c[i][j] = c[i+1][j+1] + 1;
      else
        c[i][j] = max(c[i+1][j], c[i][j+1]);
}

void reconstruct(int m, int n, FILE *out) {
  int i = 1, j = 1;
  while ( i <= m && j <= n ){
    if ( a[i] == b[j] ){
      fprintf(out, "%d ", a[i]);
      i++;
      j++;
    }
    else if ( c[i+1][j] >= c[i][j+1] )
      i++;
    else
      j++;
  }
}

int main()
{
  FILE *in  = fopen("cmlsc.in","r");
  FILE *out = fopen("cmlsc.out", "w");

  fscanf(in,"%d %d", &m, &n);
  citeste( a, m, in );
  citeste( b, n, in );

  longestCommonSubsequence();
  short int result = c[1][1];
  fprintf(out,"%d\n",result);
  reconstruct(m,n,out);

  fclose(in);
  fclose(out);

  return 0;
}
