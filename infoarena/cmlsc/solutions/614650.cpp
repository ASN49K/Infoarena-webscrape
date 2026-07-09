/*** Cel mai lung subsir comun ***/
#include <stdio.h>
#include <memory.h>

int a[1024];
int b[1024];
int maxLength[1024];
int sol[1024];
int m, n, max;
FILE *fin, *fout;

void calcCMLSC()
{
    int tempSol[1024];
    memset(tempSol, 0, sizeof(int) * 1024);
    for (int i = 0; i < m; ++i)
    {
        int best = 0;
        int tempBest = 0;
        int ai = a[i];
        for (int j = 0; j < n; ++j)
        {
            int prevBest = maxLength[j];
            if (ai == b[j])
            {
                tempSol[best] = b[j];
                maxLength[j] = ++best;
            }
            if (best + 1 == prevBest)
            {
                tempSol[best] = b[j];
                best = prevBest;
            }
        }

        if (max < best)
        {
            max = best;
            memcpy(sol, tempSol, max * sizeof(int));
        }
    }

    fprintf(fout, "%d\n", max);
    if (max > 0)
    {
        for (int i = 0; i < max - 1; ++i) fprintf(fout, "%d ", sol[i]);
        fprintf(fout, "%d", sol[max - 1]);
    }
}

int main(void)
{
    fin = fopen("cmlsc.in", "r");
    fout = fopen("cmlsc.out", "w");

    int i;
    fscanf(fin, "%d %d", &m, &n);
    for (i = 0; i < m; ++i) fscanf(fin, "%d", &a[i]);
    for (i = 0; i < n; ++i) fscanf(fin, "%d", &b[i]);

    calcCMLSC();

    return 0;
}