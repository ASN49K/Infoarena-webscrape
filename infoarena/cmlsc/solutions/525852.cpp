#include <cstdio>
#include <cstdlib>
using namespace std;

void printSol(int **C, int i, int j, int *X, int *Y);

int main(void)
{
  int m, n, i, j;
  int *X, *Y;
  int **C;

  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
    
  scanf("%d %d",&m,&n);
  
  X = new int[m];
  for (i=0;i<m;++i)
  {
    scanf("%d",&X[i]);
  }

  Y = new int[n];  
  for (i=0;i<n;++i)
  {
    scanf("%d",&Y[i]);
  }

  C = new int* [m+1];
  for (int i=0;i<=m;i++)
  {
    C[i] = new int[n+1];
  }

  for (i=1;i<=m;++i)
  {
    C[i][0] = 0;
  }
  for (j=0;j<=n;++j)
  {
    C[0][j] = 0;
  }

  for (i=1;i<=m;++i)
  {
    for (j=1;j<=n;++j)
    {
      if (X[i-1] == Y[j-1])
      {
        C[i][j] = C[i-1][j-1] + 1;        
      }
      else if (C[i-1][j] >= C[i][j-1])
      {
        C[i][j] = C[i-1][j];
      }
      else
      {
        C[i][j] = C[i][j-1];
      }
    }
  }

  printf("%d\n",C[m][n]);
  printSol(C,m,n,X,Y);
  printf("\n");

  for (int i=0;i<=m;i++)
  {
    delete[] C[i];
  }
  delete[] C;
  delete[] X;
  delete[] Y;

  return 0;
}

void printSol(int **C, int i, int j, int *X, int *Y)
{
  if (i==0 || j ==0) return;
  
  if (X[i-1] == Y[j-1])
  {
    printSol(C,i-1,j-1,X,Y);
    printf("%d ",X[i-1]);
  }
  else if (C[i-1][j] > C[i][j-1])
  {
    printSol(C,i-1,j,X,Y);
  }
  else printSol(C,i,j-1,X,Y);
}
