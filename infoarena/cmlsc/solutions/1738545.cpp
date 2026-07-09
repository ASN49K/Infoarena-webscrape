#include <stdio.h>

int n, m, a[1025], b[1025], v[1025][1025], sir[1025], bst;
int maxim(int a, int b) { return (a>b)? a : b; }

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &b[i]);
    for(int i=1; i<=m; ++i)
        scanf("%d", &a[i]);
    
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            if(a[i]==b[j])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = maxim(v[i-1][j], v[i][j-1]);
    printf("%d\n", v[n][m]);

    for(int i=m, j=n; i;)
        {
            if(a[i]==b[j]) sir[bst++] = a[i];
            else if(v[i-1][j]>v[i][j-1]) i--;
            else j--;
        }
    for(int i=0; i<bst; ++i) printf("%d ", sir[i]);

    return 0;
}