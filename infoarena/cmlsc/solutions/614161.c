#include <stdio.h>
#define NMAX 1030

int v[NMAX], w[NMAX], a[NMAX][NMAX];

void afis(int i, int j, FILE *fout)
{
    if(i<1 || j<1)
        return;

    if(v[i] == w[j])
    {
        afis(i-1, j-1, fout);
        fprintf(fout, "%d ", v[i]);
    }
    else
        if(a[i-1][j] > a[i][j-1])
            afis(i-1, j, fout);
        else
            afis(i, j-1, fout);
}

int main()
{
    FILE *fin, *fout;
    int m, n, i, j;

    fin = fopen("cmlsc.in", "rt");
    fout = fopen("cmlsc.out", "wt");

    fscanf(fin, "%d %d", &m, &n);
    for(i=1; i<=m; i++)
        fscanf(fin, "%d", v+i);
    for(i=1; i<=n; i++)
        fscanf(fin, "%d", w+i);

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(v[i] == w[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = a[i-1][j]>a[i][j-1] ? a[i-1][j] : a[i][j-1];
        }

    fprintf(fout, "%d\n", a[m][n]);
    afis(m, n, fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
