#include <stdio.h>

int a[1030], b[1030], c[1030][1030], d[1030];
int main(void)
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int m, n, k=0, i, j;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++)
        scanf("%d", &a[i]);

    for(j=1;j<=m;j++)
        scanf("%d", &b[j]);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;

            else
                if(c[i-1][j]>c[i][j-1])
                    c[i][j]=c[i-1][j];
        }

    i=n, j=m;
    while(i!=0 or j!=0)
    {
        if(a[i]==b[j])
        {
            d[++k]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j]<c[i][j-1])
            j--;
        else
            i--;
    }

    //printf("%d\n", k);
    for(int l=k;l>0;l--)
        printf("%d ", d[l]);

    return 0;
}
