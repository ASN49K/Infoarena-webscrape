#include <stdio.h>
#include <stdlib.h>
#define dim 1024

int d[dim][dim];

int max(int i, int j)
{
if (d[i-1][j]>d[i][j-1])
    return d[i-1][j];
return d[i][j-1];
}

int main()
{
    //ini
    int a[dim],b[dim],c[dim];
    int m,n,i,j,l;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    //read
    scanf("%d %d",&m,&n);
    for (i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for (i=1;i<=n;i++)
        scanf("%d",&b[i]);
    //mat build
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(i,j);
    //afisez max
    l=d[m][n];
    printf("%d\n",l);
    //remake
    i=m;
    j=n;
    while (l!=0)
    {
        if(a[i]==b[j])
        {
            l--;
            c[l]=a[i];
            i--;
            j--;
        }
        else
            if (d[i][j-1]>d[i-1][j])
                j--;
            else
                i--;
    }
    //afis
    for (i=0;i<d[m][n];i++)
        printf("%d ",c[i]);
    return 0;
}
