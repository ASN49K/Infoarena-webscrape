#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

//#define MAX 1000

void cmlsc(int a[], int b[], int m, int n, FILE *f)
{
     int mat[m][n], i, j, k, max, max_mod;
     
     for (i = 0, j = 0; i < n; i++)
     {   if (a[i] == b[0])
            j = 1;
         mat[0][i] = j;
     }
     
     for (i = 1; i < m; i++)
     {   for (j = 0, max_mod = 0; j < n; j++)
         {   max = mat[i-1][j];
             for (k = 0; k < j; k++)
                 if (max < mat[i][k])
                    max = mat[i][k];
             if (a[j] == b[i] && !max_mod)
             {  mat[i][j] = max + 1;
                max_mod = 1;
             }
             else
                mat[i][j] = max;
         }
     }
     
     fprintf(f, "%i\n", mat[m-1][n-1]);
     for (i = 1; i < m; i++)
     {   if (mat[i][n-1] > mat[i-1][n-1])
            fprintf(f,"%i ", b[i]);
     }
     /*
     printf("\n\n");
     
     for (i = 0; i < m; i++)
     {   for (j = 0; j < n; j++)
             printf("%3i", mat[i][j]);
         printf("\n");
     }
     */
}

int main()
{
    int m, n, i;
    FILE *f, *g;
    
    f = fopen("cmlsc.in", "r");
    
    fscanf(f, "%i%i", &m, &n);
    int a[m], b[n];
    for (i = 0; i < m; ++i)
        fscanf(f, "%i", a+i);
    for (i = 0; i < n; ++i)
        fscanf(f, "%i", b+i);
    
    g = fopen("cmlsc.out", "w");
    if (m < n)
       cmlsc(b, a, m, n, g);
    else
       cmlsc(a, b, n, m, g);
    
    //getch();
    return 0;
}
