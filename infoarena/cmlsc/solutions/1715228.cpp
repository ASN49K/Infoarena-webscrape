#include <stdio.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
int res[1025][1025];
struct {
  int i;
  int j;
}parent[1025][1025];

void print(int i, int j);
FILE *fin, *fout;

int x[1025] = { 0 };
int y[1025] = { 0 };

int main()
{
  int m, n;

  fin = fopen("cmlsc.in", "r");
  fscanf(fin, "%d %d", &m, &n);

  for (int i = 1; i <= m; i++)
  {
    fscanf(fin, "%d", &x[i]);
  }
  
  for (int i = 1; i <= n; i++)
  {
    fscanf(fin, "%d", &y[i]);
  }

  fclose(fin);

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
      if (x[i] == y[j])
      {
        res[i][j] = res[i - 1][j - 1] + 1;
        parent[i][j].i = i - 1;
        parent[i][j].j = j - 1;
      }
      else
      {
        if(res[i - 1][j] > res[i][j - 1])
        {
          parent[i][j].i = i - 1;
          parent[i][j].j = j;
          res[i][j] = res[i - 1][j];
        }
        else
        {
          parent[i][j].i = i;
          parent[i][j].j = j - 1;
          res[i][j] = res[i][j - 1];
        }
      }
    }

  fout = fopen("cmlsc.out", "w");
  fprintf(fout, "%d\n", res[m][n]);
  
  print(m, n);
  fclose(fout);
  return 0;
}

void print(int i, int j)
{
  if (i == 0 || j == 0)
    return;
  print(parent[i][j].i, parent[i][j].j);

  if (parent[i][j].i == i - 1 && parent[i][j].j == j - 1)
  {
    fprintf(fout, "%d ", x[i]);
  }
}