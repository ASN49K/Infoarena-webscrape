#include <iostream>
#include <stdio.h>

#define maxim(a,b) (a>b)?a:b

using namespace std;

struct mat
{
    char lsc;
    char dir;
}v[1025][1025];


char a[1025], b[1025], sol[1025];

int main()
{
    int n,m, i, j;
    int cmlsc_length;
    FILE *fin = fopen("cmlsc.in","r");
    FILE *fout = fopen("cmlsc.out", "w");

    fscanf(fin, "%d %d", &n, &m);
    for (i=1;i<=n;i++)
        fscanf(fin,"%d ", &a[i]);
    for (i=1;i<=m;i++)
        fscanf(fin, "%d ", &b[i]);

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            if (a[i] == b[j])
            {
                v[i][j].lsc = v[i-1][j-1].lsc+1;
                v[i][j].dir = 1;
            }

            else
            {
                if (v[i-1][j].lsc > v[i][j-1].lsc)
                {
                    v[i][j].lsc = v[i-1][j].lsc;
                    v[i][j].dir = 2;
                }
                else
                {
                    v[i][j].lsc = v[i][j-1].lsc;
                    v[i][j].dir = 3;
                }
            }

        }

    //reconstructia sirului

    i = n;
    j = m;
    while (v[i][j].lsc != 0)
    {
        if (v[i][j].dir == 1)   //aici o crescut solutia
        {
            sol[v[i][j].lsc] = a[i];
            i--;j--;
        }
        else
            if (v[i][j].dir == 2)
            {
                i--;
            }
            else
                if (v[i][j].dir == 3)
                {
                    j--;
                }
    }


   /* for (i=0;i<=n;i++)        //sa vad doar daca e bine pana aici
    {
        for (j=0;j<=m;j++)
            fprintf(fout, "%d ", v[i][j].lsc);
        fprintf(fout,"\n");
    }
    fprintf(fout,"\n");

    for (i=0;i<=n;i++)
    {
        for (j=0;j<=m;j++)
            fprintf(fout, "%d ", v[i][j].dir);
        fprintf(fout,"\n");
    }*/


    cmlsc_length = v[n][m].lsc;
    fprintf(fout, "%d\n", cmlsc_length);

    for (i=1;i<=cmlsc_length;i++)
        fprintf(fout,"%d ", sol[i]);

    fclose(fin);
    fclose(fout);
}
