#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int m, n, a[MAX+1], b[MAX+1];
int lcs[MAX+1], c[MAX+1][MAX+1], bst;

void citeste(int v[], int n, FILE *in) {
  int i;
  for ( i = 1; i <= n; i++ )
    fscanf(in, "%d", &v[i]);
}

int max(int a, int b) {
  return a > b ? a : b;
}

void longestCommonSubsequence() {
  int i, j;
  for ( i = 1; i <= m; i++ )
    for ( j = 1; j <= n; j++)
      if ( a[i] == b[j] )
        c[i][j] = 1 + c[i-1][j-1];
      else
        c[i][j] = max( c[i-1][j], c[i][j-1] );
}

void reconstruct() {
  int i, j;
  for ( i = m, j = n; i; )
    if ( a[i] == b[j] ){
      lcs[++bst] = a[i];
      i--;
      j--;
    }
    else if ( c[i-1][j] < c[i][j-1] )
      j--;
    else
      i--;
}

void afisare(FILE *out) {
  int i;
  fprintf(out,"%d\n",bst);
  for ( i = bst; i; --i)
    fprintf(out, "%d ", lcs[i] );
}

int main()
{
  FILE *in  = fopen("cmlsc.in","r");
  FILE *out = fopen("cmlsc.out", "w");

  fscanf(in,"%d %d", &m, &n);
  citeste( a, m, in );
  citeste( b, n, in );

  longestCommonSubsequence();
  reconstruct();
  afisare(out);

  fclose(in);
  fclose(out);

  return 0;
}
