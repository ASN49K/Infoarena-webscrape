#include <stdio.h>
#include <stdlib.h>

int maxx(int a, int b)
{
    return a>=b?a:b;
}

int lcs( int *X, int *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1]) //m-1 is the index of last element of X and same for Y
        return 1 + lcs(X, Y, m-1, n-1); //if we find 2 matching we increase length
    else
        return maxx(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); //we include and exclude consequently and chose the max of this
}

void lcs_dynamic( int *X, int *Y, int m, int n, FILE *fp )
{
   int L[m+1][n+1];

   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = maxx(L[i-1][j], L[i][j-1]);
     }
   }

   int index = L[m][n];
   fprintf(fp, "%d\n", index);
   int lcs[index+1];

   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1];
          i--; j--; index--;
      }

      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
    for(int i=0; i<L[m][n]; i++)
    {
        fprintf(fp, "%d ", lcs[i]);
    }
}
int main()
{
   /*
    int a[10]={1, 2, 3, 1, 7};
    int b[10]={1, 2, 6, 3, 1, 9};
    printf("\n%d", lcs_dynamic(a, b, 5, 6));
    */
    FILE *fin=fopen("cmlsc.in", "r");
    FILE *fout=fopen("cmlsc.out", "w");
    int m, n;
    fscanf(fin, "%d %d", &m, &n);
    int a[m], b[n]; int temp;
    for(int i=0; i<m; i++)
    {
        fscanf(fin, "%d", &temp);
        a[i]=temp;
    }
    for(int i=0; i<n; i++)
    {
        fscanf(fin, "%d", &temp);
        b[i]=temp;
    }
    lcs_dynamic(a, b, m, n, fout);
    return 0;
}
