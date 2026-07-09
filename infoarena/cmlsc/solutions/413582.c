#include <stdio.h>
#include <stdlib.h>

#define UP    0
#define LEFT  1
#define DIAG  2

int *x,*y,*sol;
char **c, **b;
int n ,m ;
int max;

int maxim(int a, int b)
{
  if (a > b) return a;
  else return b;
}

void read(char * name)
{
  FILE* fin = fopen("cmlsc.in", "r");
  fscanf(fin, "%d%d", &n ,&m);
  int i , j ;
  n++;
  m++;
  x = (int*)malloc(sizeof(int) * n);
  y = (int*)malloc(sizeof(int) * m);
  sol = (int*)malloc(sizeof(int) * maxim(n,m));
  b = (char**)malloc(sizeof(char*) * n);   // retine calea
  c = (char**)malloc(sizeof(char*) * n);
  for (i = 0 ; i < n ; i++)
  {
      c[i] = (char*)malloc(sizeof(char) * m);
      b[i] = (char*)malloc(sizeof(char) * m);
      for (j = 0 ; j < m ; j++)
          c[i][j] = b[i][j] = 0;
  }
  for (i = 1 ; i < n ; i ++ )
      fscanf(fin , "%d ", &(x[i]));
  for (i = 1 ; i < m ; i ++ )
      fscanf(fin , "%d ", &(y[i]));
  fclose(fin);
}
void solve()
{
  int i, j;
  for( i = 1 ; i < n ; i++)
      for ( j = 1 ; j < m ; j++)
      {
        if (x[i] == y[j]){
          c[i][j] = 1 + c[i - 1][j - 1];
          b[i][j] = DIAG;
        }
        else{
          if (c[i - 1][j] > c[i][j - 1]){
            c[i][j] = c[i - 1][j];
            b[i][j] = UP;
          }
          else{
            c[i][j] = c[i][j - 1];
            b[i][j] = LEFT;
          }
        }
      }
    int index, ii, jj;
    max = index = c[n - 1][m - 1];
    ii = n - 1 ; jj = m -1;
    while (index != 0)
    {
      if ( b[ii][jj] == DIAG )
      {
        sol[index] = x[ii];
        ii--;jj--;
        index--;
      }
      else if ( b[ii][jj] == UP )
        ii--;
      else if ( b[ii][jj] == LEFT )
        jj--;
    }
}

void save()
{
  int i;
  FILE* fout = fopen("cmlsc.out", "w");
  fprintf(fout,"%d\n", max);
  for ( i = 1 ; i <= max ; i++)
      fprintf(fout,"%d ", sol[i]);
  fclose(fout);
}
int main(void)
{
  read("cmlsc.in");
  solve();
  save();
  return 0;
}
