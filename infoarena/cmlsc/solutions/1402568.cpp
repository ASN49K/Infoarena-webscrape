#include <iostream>
#include <fstream>
#include <cstdio>
#define NMax 1025
using namespace std;
ofstream g("cmlsc.out");
int m, n, a[NMax], b[NMax], d[NMax][NMax], sir[NMax], best;

int main()
{
    int i, j;
    freopen("cmlsc.in", "r", stdin);
    scanf("%d %d", &m, &n);
    for(i=1;i<=m;i++)
        scanf("%d", &a[i]);
    for (i=1;i<=n;i++)
        scanf("%d", &b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);

    for (i = m, j = n; i; )
        if (a[i] == b[j])
        {
            sir[++best] = a[i];
             --i;
             --j;
        }
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;

    g<<best<<'\n';
    for (i = best; i; --i)
        g<<sir[i]<<" ";

    return 0;
}
