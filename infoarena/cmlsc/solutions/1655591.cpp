#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1025], b[1025];
int d[1025][1025];

int sol[1025], nr = 0;

int main()
{
    FILE *fin, *fout;

    fin = fopen("cmlsc.in", "r");
    fout = fopen("cmlsc.out", "w");

    int m, n;

    fscanf(fin, "%d%d", &m, &n);

    for(int i = 1; i <= m; i++)
        fscanf(fin, "%d", &a[i]);

    for(int i = 1; i <= n; i++)
        fscanf(fin, "%d", &b[i]);


    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[j][i - 1]);
        }

    //fprintf(fout, "%d\n", d[m][n]);

    int i = m, j = n;

    while(i && j)
    {
        if(a[i] == b[j])
        {
            sol[++nr] = a[i];
            i--;
            j--;
        }
        else if(d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;
    }

    fprintf(fout, "%d\n", nr);

    for(int i = nr; i >= 1; i--)
        fprintf(fout, "%d ", sol[i]);


    return 0;
}
