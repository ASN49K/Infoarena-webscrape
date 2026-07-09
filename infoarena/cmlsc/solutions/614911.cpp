/*** Cel mai lung subsir comun ***/
#include <stdio.h>
#include <memory.h>

#define max(a, b) ((a) > (b) ? a : b)

int a[1025];
int b[1025];
int sol[1025][1025];
int m, n;
FILE *fin, *fout;

void calcCMLSC()
{
    int ai;
    for (int i = 1; i <= m; i++)
    {
        ai = a[i];
        for (int j = 1; j <= n; j++)
        {
            if (ai == b[j])
                sol[i][j] = sol[i - 1][j - 1] + 1;
            else
                sol[i][j] = max(sol[i - 1][j], sol[i][j- 1]);
        }
    }

    int solution[1025];
    int max = 0;
    for (int i = m, j = n; i > 0;)
    {
        if (a[i] == b[j])
        {
            solution[++max] = a[i];
            --i;
            --j;
        }
        else if (sol[i - 1][j] > sol[i][j - 1])
            --i;
        else
            --j;
    }

    fprintf(fout, "%d\n", max);
    for (int i = max; i > 0; --i)
        fprintf(fout, "%d ", solution[i]);
}

int main(void)
{
    fin = fopen("cmlsc.in", "r");
    fout = fopen("cmlsc.out", "w");

    int i;
    fscanf(fin, "%d %d", &m, &n);
    for (i = 1; i <= m; ++i) fscanf(fin, "%d", &a[i]);
    for (i = 1; i <= n; ++i) fscanf(fin, "%d", &b[i]);

    calcCMLSC();

    return 0;
}