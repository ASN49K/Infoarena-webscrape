#include <stdio.h>
#define NMAX 1024
#define maxim(a, b) ((a > b) ? a : b)
int v1[NMAX], v2[NMAX], matr[NMAX][NMAX], sol[NMAX], k;
using namespace std;

void afisare (int i, int j)
{
   if ( i >= 1 && j >= 1)
   {
       if (v1[i] == v2[j])
       {
            afisare(i - 1, j - 1);
            sol[k] = v1[i];
            k++;

       }
       else
       {
           if (matr[i-1][j] < matr[i][j-1])
            afisare(i, j - 1);
           else
            afisare(i - 1, j);
       }
   }
}

int main()
{
    int i, j, n, m;
    FILE *f, *g;

    f = fopen("cmlsc.in", "r");
    g = fopen("cmlsc.out", "w");
    fscanf(f, "%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        fscanf(f, "%d", &v1[i]);
    for (i = 1; i <= m; i++)
        fscanf(f, "%d", &v2[i]);
    fclose(f);

    for (i = 0; i <= n; i++)
        for ( j = 0; j <= m; j++)
        {
                if ( i == 0 || j == 0)
                    matr[i][j] = 0;
                else
                {
                    if (v1[i] == v2[j])
                        matr[i][j] = 1 + matr[i-1][j-1];
                    else
                        matr[i][j] = maxim(matr[i-1][j],matr[i][j-1]);
                }
        }
    afisare(n ,m);
    fprintf(g, "%d\n", k);
    for (i = 0; i < k; i++)
        fprintf(g, "%d ", sol[i]);
    fclose(g);
    return 0;
}
