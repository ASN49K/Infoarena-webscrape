#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;
int d[1030][1030];
int a[1030], b[1030];
int s[1030];

void drum(int i, int j)
{
    if(!d[i][j])
        return;

    if(a[i] == b[j])
    {
        drum(i-1,j-1);
        printf("%d ", a[i]);
        return;
    }

    if(d[i-1][j] <= d[i][j-1])
            drum(i,j-1);
        else
            drum(i-1,j);
}

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

    drum(n,m);

    return 0;
}
