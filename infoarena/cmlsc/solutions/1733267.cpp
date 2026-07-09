#include <stdio.h>

#define For(i, a, b) for (i = a; i <= b; ++i)
#define maxi(x, z) ((x > z) ? x : z)
#define z 1024

int m, n, k=0, a[z], b[z], c[z][z], d[z];
int main(void)
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int   i, j;
    scanf("%d %d", &n, &m);
    For(i,1,n)
        scanf("%d", &a[i]);

    For(i,1,m)
        scanf("%d", &b[i]);

    For(i,1,n)
        For(j,1,m)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=maxi(c[i-1][j],c[i][j-1]);

    for (i=n,j=m; i, j; )
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

    printf("%d\n", k);
    for (i = k; i; --i)
        printf("%d ", d[i]);

    return 0;
}
