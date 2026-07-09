#include <stdlib.h>
#include <stdio.h>

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int mat[100][100];

int main()
{
  int s1[100], s2[100], i,j, n, m, rez[100], nrElem=0;

   FILE* in    = fopen("cmlsc.in", "r");
   FILE* out = fopen("cmlsc.out", "a");

    fscanf(in, "%d %d", &n, &m);

    for(int i=0; i<n; i++)
      fscanf(in, "%d", &s1[i]);

    for(int i=0; i<m; i++)
      fscanf(in, "%d", &s2[i]);

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
          if(s1[i] == s2[j])
          {
              if(i==0 && j==0)
                mat[i][j] = 0;
             else
                mat[i][j] = mat[i-1][j-1] + 1;
          }
          else
              mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
      }
    }

  for(int i=n, j=m; i !=-1 && j!=-1; )
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
