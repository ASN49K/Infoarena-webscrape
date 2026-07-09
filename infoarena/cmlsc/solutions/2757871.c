#include <stdio.h>

#define MAX 1024
#define max(a, b) (a > b? a: b)

int a[MAX], b[MAX], n, m, back, sir[MAX], i, j, cost[MAX][MAX];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for(i = 1; i <=n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i <=m; i++)
        scanf("%d", &b[i]);

    for(i = 1; i<=n; i++)
        for(j = 1; j <=m; j++)
        {
            if(a[i]==b[j])
                cost[i][j] = cost[i-1][j-1]+1;
            else cost[i][j] = max(cost[i-1][j], cost[i][j-1]);
        }

    for(i = n, j=m; i;)
    {
        if(a[i]==b[j])
        {
            sir[++back] = a[i];
            i--, j--;
        }
        else if(cost[i][j-1] > cost[i-1][j])
                j--;
        else i--;

    }

    printf("%d\n", cost[n][m]); // back tot e raspuns
    for(i = back; i; i--)
        printf("%d ", sir[i]);

    return 0;
}
