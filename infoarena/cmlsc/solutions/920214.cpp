#include <cstdio>
#define maxim(a, b) ((a > b) ? a : b)
int n, m, i, j, sir[1025], d[1025][1025], a[1025], b[1025], bst;
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for(i=1;i<=m;i++)
        scanf("%d", &a[i]);
    for(i=1;i<=n;i++)
        scanf("%d", &b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=maxim(d[i-1][j], d[i][j-1]);
    for(i=m, j=n;i;)
        if(a[i]==b[j])
            sir[++bst]=a[i], i--, j--;
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    printf("%d\n", bst);
    for(i=bst;i>=1;i--)
        printf("%d ", sir[i]);
    printf("\n");
    return 0;
}
