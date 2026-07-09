#include <iostream>
#include <stdio.h>

#define maxim(a,b) (a>b)?a:b

using namespace std;

char a[1025], b[1025], sol[1025], v[1025][1025];

int main()
{
    int n,m, i, j, aux;
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
               v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = maxim(v[i-1][j], v[i][j-1]);
        }

    //reconstructia sirului
    cmlsc_length = v[n][m];
    aux = cmlsc_length;
    i = n;
    j = m;
    while (i!=0 )
    {
        if (a[i] == b[j])
        {
            sol[aux--] = a[i];
            i--;j--;
        }
        else
            if (v[i-1][j] > v[i][j-1])
                i--;
            else
                j--;
    }


    fprintf(fout, "%d\n", cmlsc_length);

    for (i=1;i<= cmlsc_length;i++)
        fprintf(fout,"%d ", sol[i]);

    fclose(fin);
    fclose(fout);
}
