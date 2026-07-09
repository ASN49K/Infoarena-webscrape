#include <stdio.h>

#define maxim(a, b) ((a > b) ? a : b)
#define NMax 1024



int m, n, a[NMax], b[NMax], d[NMax][NMax], sir[NMax], bst;

int main(void)
{
    int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for (int i=1;i<=m;++i){
        scanf("%d", &a[i]);
    }
    for (int i=1;i<=n;++i){
        scanf("%d", &b[i]);
    }

    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j){
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
        }
    }

    for (i = m, j = n; i>0;)
        if (a[i] == b[j]){
            sir[++bst] = a[i];
            --i;
            --j;
        }
        else if (d[i-1][j] < d[i][j-1]){
            --j;
        }
        else{
            --i;
        }

    printf("%d\n", bst);
    for (i = bst; i>0; --i)
        printf("%d ", sir[i]);

    return 0;
}
