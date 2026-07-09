#include <stdlib.h>
#include <stdio.h>

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int mat[100][100], s1[100], s2[100], n, m, rez[100], nrElem=0;

int main()
{

   FILE* in    = fopen("cmlsc.in", "r");
   FILE* out = fopen("cmlsc.out", "w");

    fscanf(in, "%d %d", &n, &m);

    for(int i=1; i<=n; i++)
      fscanf(in, "%d", &s1[i]);

    for(int i=1; i<=m; i++)
      fscanf(in, "%d", &s2[i]);

    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++)
          if(s1[i] == s2[j])
            mat[i][j] = mat[i-1][j-1] + 1;
          else
            mat[i][j] = max(mat[i-1][j], mat[i][j-1]);

    for(int i=n, j=m; i; )
    {
      if(s1[i] == s2[j])
      {
          rez[nrElem++] = s1[i];
          --i; --j;
      }
      else if(mat[i][j-1] < mat[i-1][j])
        --i;
      else
        --j;
  }

  fprintf(out, "%d\n", nrElem);
  for(int i=nrElem-1; i>=0; --i)
    fprintf(out, "%d ", rez[i]);

  return 0;
}
