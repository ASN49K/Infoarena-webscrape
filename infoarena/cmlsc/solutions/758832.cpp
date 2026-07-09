#include <cstdio>
#define NMAX 1025

int n, m, v1[NMAX], v2[NMAX], r[NMAX][NMAX];
FILE *in, *out;

int max(int a, int b)
{
    return a > b ? a : b;
}

void reconstituire(int n, int m, int poz )
{
     if( poz == 0)
         return;
     if (v1[n] == v2[m])    
     {
           reconstituire(n -1, m -1, poz - 1);
           fprintf(out, "%d ", v1[n]);
     }
     else
     if (r[n-1][m] > r[n][m-1])
        reconstituire(n - 1, m, poz);
     else
        reconstituire(n, m - 1, poz);   
}

int main()
{
    int i, j;
    
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");
    fscanf(in, "%d %d", &n, &m);
    for ( i = 1; i <= n; i++)
        fscanf(in, "%d", &v1[i]);
    
    for ( i = 1; i <= m; i++)
        fscanf(in, "%d", &v2[i]);
        
    for ( i = 1; i <= n; i++)
        for ( j = 1; j <= m; j++)
            if ( v1[i] == v2[j]) 
               r[i][j] = r[i-1][j-1] + 1;
            else
               r[i][j] = max(r[i-1][j], r[i][j-1]);
               
    fprintf(out, "%d\n", r[n][m]);  
    reconstituire(n, m, r[n][m]);  
    fclose(in);
    fclose(out);
    return 0;
}

