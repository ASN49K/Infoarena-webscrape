#include <iostream>

#include <cstdio>

using namespace std;

FILE *f, *g;

int n, m, a[1025], b[1025], mx[1025][1025], sir[1025], k;

void readFile()
{
    int i,j;

    f = fopen("cmlsc.in", "r");

    fscanf(f, "%d%d", &n, &m);

    for(i = 1; i <= n; i ++)
        fscanf(f, "%d", &a[i]);

    for(j = 1; j <= m; j ++)
        fscanf(f, "%d", &b[j]);

    fclose(f);
}

inline int mxa(int a, int b)
{
    return (a > b ? a : b);
}

void solve()
{
    int i, j;

    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= m; j ++)
        {




            if(a[i] == b[j])
                mx[i][j] = mx[i - 1][j - 1] + 1;

            else
                mx[i][j] = mxa(mx[i - 1][j], mx[i][j - 1]);
        }
    }

    for(i = n, j = m; (i != 0) && (j != 0);)
    {
        if(a[i] == b[j])
        {
            sir[++ k] = a[i];

            i --;
            j --;
        }

        else
            if(mx[i - 1][j] > mx[i][j - 1])
                i --;

        else
            j --;
    }
}

void printFile()
{
    int i;

    g = fopen("cmlsc.out", "w");

    fprintf(g, "%d\n", k);

    for(i = k; i >= 1; i --)
        fprintf(g, "%d ", sir[i]);

    fclose(g);
}

int main()
{
    readFile();

    solve();

    printFile();

    return 0;
}
