#include <stdio.h>

#define maxi(x, z) ((x > z) ? x : z)
#define z 1024

int m, n, k=0, a[z], b[z], c[z][z], d[z];
int main(void)
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int   i, j;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;++i)
        scanf("%d", &a[i]);

    for(i=1;i<=m;++i)
        scanf("%d", &b[i]);

    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;

            else
                c[i][j]=maxi(c[i-1][j],c[i][j-1]);
        }

    for (i=n,j=m; i, j; )
    {
        if(a[i]==b[j])
        {
            d[++k]=a[i];
            --i;
            --j;
        }
        else if(c[i-1][j]<c[i][j-1])
            --j;
        else
            --i;
    }

    printf("%d\n", k);
    for(int l=k;l>0;l--)
        printf("%d ", d[l]);

    return 0;
}
