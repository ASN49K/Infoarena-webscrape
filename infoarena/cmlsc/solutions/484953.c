#include <stdio.h>

#define SIZE 1024
#define MAX(x,y) ((x < y) ? y : x)

int d[SIZE][SIZE];

int
main (int argc, char *argv[])
{
  FILE *fin, *fout;
  int m, n, i, j, k, a[SIZE], b[SIZE], btrace[SIZE];

  fin = fopen ("cmlsc.in", "rt");
  fout = fopen ("cmlsc.out", "wt");

  fscanf (fin, "%d", &m);
  fscanf (fin, "%d", &n);

  for (i = 1; i <= m; i++)
    fscanf (fin, "%d", &a[i]);

  for (j = 1; j <= n; j++)
    fscanf (fin, "%d", &b[j]);

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      {
	if (a[i] == b[j])
	  d[i][j] = d[i - 1][j - 1] + 1;
	else
	  d[i][j] = MAX (d[i - 1][j], d[i][j - 1]);
	printf ("d[%d][%d] = %d\n", i, j, d[i][j]);
      }

  for (k = 1, i = m, j = n; i; )
    if (a[i] == b[j])
      {
	btrace[k] = a[i];
	i--, j--; k++;
      }
    else if (d[i - 1][j] < d[i][j - 1])
      j--;
    else
      i--;

  fprintf (fout, "%d\n", k - 1);
  for (i = k - 1; i; i--)
    fprintf (fout, "%d ", btrace[i]);

  fclose (fin);
  fclose (fout);

  return 0;
}
