#include <stdio.h>
#include <stdlib.h>
#define maxim(a, b) ((a > b) ? a : b)
#define max 1024


int idx,c[max][max],a[max], b[max],sir[max], n,m;
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int i,j;


    scanf("%d %d", &m, &n);

    for(i=1; i<=m; i++)
    {
        scanf("%d", &a[i]);
    }
    for(j=1; j<=n; j++)
    {
        scanf("%d", &b[j]);
    }


    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i]==b[j])
            {
                c[i][j]=1+c[i-1][j-1];
            }
            else c[i][j]= maxim(c[i-1][j],c[i][j-1]);
        }
    }


    for(i=m, j=n; i>0 && j>0;)
    {
        if(a[i]==b[j])
        {
            sir[++idx]=a[i];
            --i;
            --j;

        }
        else if(c[i-1][j]<c[i][j-1])
        {
            --j;
        }
        else --i;
    }

    printf("%d\n", c[m][n]);


    for (i = idx; i; --i)
        printf("%d ", sir[i]);





    return 0;
}
