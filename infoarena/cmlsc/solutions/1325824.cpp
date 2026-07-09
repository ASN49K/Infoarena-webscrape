#include <stdio.h>
short int m,n,a[1024],b[1024],v[1024][1024],sir[1024],bst;
short int maxim(short int v,short int b)
{
    if(v>b) return v;
    return b;
}
int main(void)
{
    int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%hd %hd", &m, &n);
    for(i=1; i<=m; i++)scanf("%hd", &a[i]);
    for(i=1; i<=n; i++)scanf("%hd", &b[i]);
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)if (a[i] == b[j])v[i][j] = 1 + v[i-1][j-1];
            else v[i][j] = maxim(v[i-1][j], v[i][j-1]);

    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], i--, j--;
        else if (v[i-1][j] < v[i][j-1])j--;
        else i--;

    printf("%hd\n", bst);
    for (i = bst; i; --i)
        printf("%hd ", sir[i]);

    return 0;
}
