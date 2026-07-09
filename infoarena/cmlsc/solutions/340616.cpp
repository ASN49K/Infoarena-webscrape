#include<stdio.h>
int m;
int n;
int solutie[1028];
int mat[1026][1026];
int contor;
int A[1026];
int B[1026];
int i;
int j;
int maxim(int x1, int y1)
{
    if (x1 > y1) return x1;
    return y1;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&m,&n);

    for(int i = 1; i <= m; i++)
     scanf("%d",&A[i]);
    for(int i = 1; i <= n; i++)
     scanf("%d",&B[i]);
    for(int i = 1; i <= m; i++)
     for(int j = 1; j <= n; j++)
     {
       if (A[i] == B[j])
       {
           mat[i][j] = mat[i-1][j-1] + 1;
       }
          else
           mat[i][j] = mat[i-1][j-1];
       mat[i][j] = maxim(maxim(mat[i][j],mat[i-1][j]),mat[i][j-1]);
      }
      i = m;
      j = n;
      printf("%d\n",mat[i][j]);
      while (contor < mat[m][n])
       {

           if (mat[i][j] == mat[i-1][j-1] + 1)
            {
                solutie[++solutie[0]] = A[i];
                contor++;
                i--;j--;
            }
           else
           if (mat[i][j] == mat[i-1][j]) i--;
            else
             j--;
       }
    for(int i = solutie[0]; i >= 1; i--)
     printf("%d ",solutie[i]);
    return 0;
}
