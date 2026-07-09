#include <bits/stdc++.h>

#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, a[1025], b[1025], d[1025][1025], sir[1025], bst;

int main(void)
{
    int i, j;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];

    for(i=1;i<=m;i++)
        for (j=1;j<=n; j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);

    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;

    g<<bst<<"\n";
    for (i = bst; i; --i)
        g<<sir[i]<<" ";

    return 0;
}
