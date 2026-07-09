#include <stdio.h>
#define Nmax 1024
#define MAX(a, b) (((a)>(b))? (a) : (b))
int m, n, a[Nmax], b[Nmax], c[Nmax], d[Nmax][Nmax], max;
int main()
{
    FILE *f1 = fopen("cmlsc.in", "r");
    FILE *f2 = fopen("cmlsc.out", "w");
    fscanf(f1, "%d%d", &m, &n);
    int i, j;
    for(i = 1; i <= m; i++) fscanf(f1, "%d", &a[i]);
    for(i = 1; i <= n; i++) fscanf(f1, "%d", &b[i]);
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(a[i] == b[j]) d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = MAX(d[i-1][j], d[i][j-1]);
    for(i = m, j = n; i; )
        if(a[i] == b[j]) {
        c[++max] = a[i];
        i--; j--;
        }
        else if(d[i-1][j] < d[i][j-1]) --j;
             else --i;
    fprintf(f2, "%d\n", max);
    for(i = max; i; i--) fprintf(f2, "%d ", c[i]);
    fclose(f1);
    fclose(f2);
    return 0;
}

