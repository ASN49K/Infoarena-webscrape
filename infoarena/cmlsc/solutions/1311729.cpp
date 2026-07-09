#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;
int d[1030][1030];
int a[1030], b[1030];
int nou[1030];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d\n", &n, &m);

    for(int i=1; i<=n; ++i)
        scanf("%d ", &a[i]);

    scanf("\n");

    for(int i=1; i<=m; ++i)
        scanf("%d ", &b[i]);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j-1], max(d[i][j-1], d[i-1][j]));

    printf("%d\n", d[n][m]);

    int k = d[n][m];
    int i=n;
    int j=m;

    while(d[i][j])
    {
        if(a[i] == b[j])
        {
            nou[k] = a[i];
            --k;
            --i;
            --j;
        }
        else if(d[i-1][j] <= d[i][j-1])
            --j;
        else
            --i;
    }

    for(int i=1;i<=d[n][m];++i)
        printf("%d ", nou[i]);

    return 0;
}
