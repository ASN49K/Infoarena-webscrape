#include <stdio.h>

int n, m, a[1025], b[1025], v[1025][1025];
int maxim(int a, int b) { return (a>b)? a : b; }

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    for(int i=1; i<=m; ++i)
        scanf("%d", &b[i]);
    
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(a[i]==b[j])
                v[i][j] = maxim(v[i-1][j], maxim(v[i][j-1], v[i-1][j-1]+1));
    printf("%d", v[n][m]);

    return 0;
}