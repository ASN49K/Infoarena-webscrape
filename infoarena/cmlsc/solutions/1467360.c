#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)
#define NREL 1024

int Afisare(int C[NREL][NREL], int v1[NREL], int v2[NREL], int i, int j, int *sol, int k)
{

    if ( i >= 0 && j >= 0 )
    {

        if ( v1[i-1] == v2[j-1] )
        {
            sol[k] = v1[i-1];
            k++;
            //fprintf(g, "%d ", v1[i-1]);
            Afisare(C, v1, v2, i-1, j-1, sol, k);
        }
        else
        {
            if ( C[i][j-1] > C[i-1][j] )
                Afisare(C, v1, v2, i, j-1, sol, k);
            else
                Afisare(C, v1, v2, i-1, j, sol, k);
        }

    }


    return k;
}

int main()
{
    /* deschidere fisiere */
    FILE *f, *g;
    f = fopen("cmlsc.in", "r");
    g = fopen("cmlsc.out", "w");

    /*citire date */
    int i, j, m, n, v1[NREL], v2[NREL], C[NREL][NREL];
    fscanf(f, "%d %d", &m, &n);

    for ( i = 0 ; i < m ; i++ )
        fscanf(f, "%d", &v1[i]);

    for ( i = 0 ; i < n ; i++ )
        fscanf(f, "%d", &v2[i]);

    /*Determinare lungime */

    for ( i = 0 ; i <= m ; i++ )
        C[i][0] = 0;

    for ( j = 0 ; j <= n; j++ )
        C[0][j] = 0;

    for ( i = 1 ; i <= m; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( v1[i-1] == v2[j-1] )
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = max(C[i][j-1], C[i-1][j]);
        }
    }

    fprintf(g, "%d\n", C[m][n]);

    /* Afisare solutie */
    int sol[NREL], k = 0;

    int nr = Afisare(C, v1, v2, m, n, sol, k);

    for ( i = nr ; i >= 0 ; i-- )
        fprintf(g, "%d ", sol[i]);

    /*inchidere fisiere */
    fclose(f);
    fclose(g);

    return 0;
}
