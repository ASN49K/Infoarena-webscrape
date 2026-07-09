#include <iostream>
#include <stdio.h>

using namespace std;


int main (void)
{
  FILE *f = fopen("cmlsc.in","rt");
  FILE *g = fopen("cmlsc.out","wt");

  if (!f || !g)
  {
    cerr << "Error" << endl;
    return 1;
  }

  int n, m;
  int *A, *B;
  int **mat;

  fscanf(f, "%d %d", &n, &m);

  A = new int [n];
  B = new int [m];

  for (int i = 0 ; i < n ; i ++)
    fscanf(f, "%d", &A[i]);

  for (int i = 0 ; i < m ; i ++)
    fscanf(f, "%d", &B[i]);

  mat = new int *[n];

  for (int i = 0 ; i < n ; i ++)
    mat[i] = new int [m];

  for (int i = 0 ; i < n ; i ++)
    for (int j = 0 ; j < m ; j ++)
      mat [i][j] = 0;

  for (int i = 0 ; i < n ; i ++)
    for (int j = 0 ; j < m ; j ++)
    {
      int left = 0;
      if (j > 0)
        left = mat[i][j - 1];

      int up = 0;
      if (i > 0)
        up = mat[i - 1][j];

      int prev = 0;
      if (i > 0 && j > 0)
        prev = mat [i - 1][j - 1];

      if (A[i] == B[j])
        mat[i][j] = prev + 1;
      else
        mat[i][j] = up > left ? up : left;

    }

  // go back
  int *path;
  path = new int [mat[n - 1][m - 1]];
  
  int i = n - 1, j = m - 1;
  int max;
  int contor = 0;

  while (i > 0 || j > 0)
  {
    if (A[i] == B[j])
    {
      path[contor ++] = A[i];
      if (i > 0)
        i --;
      if (j > 0)
        j --;

      continue;
    }

    if (i == 0)
    {
      j --;
      continue;
    }

    if (j == 0)
    {
      i --;
      continue;
    }

    if (mat[i - 1][j] == mat[i][j])
      i --;
    else
      j --;
  }

  if (A[0] == B[0])
    path[contor++] = A[0];

  fprintf(g, "%d\n", contor);

  for (i = contor - 1 ; i >= 0 ; i -- )
    fprintf(g, "%d ", path[i]);

  //cin.get();

  delete [] path;
  delete [] A;
  delete [] B;

  fclose(f);
  fclose(g);

  return 0;
}