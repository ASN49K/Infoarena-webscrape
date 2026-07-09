#include <iostream>
#include <stdio.h>

using namespace std;

int n,m,i,j,a[1025],b[1025],v[1025][1025],k,nr,c[1025],x,y;

int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&m,&n);

    for (i=1;i<=m;i++)
    scanf("%d",&a[i]);

    for (i=1;i<=n;i++)
    scanf("%d",&b[i]);

    for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
    {
        if (a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
        else
        if (v[i-1][j]>v[i][j-1]) v[i][j]=v[i-1][j];
        else v[i][j]=v[i][j-1];
    }

    /*for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        printf("%d ",v[i][j]);
        printf("\n");
    }*/

    nr=v[m][n];
    printf("%d\n",nr);
    x=m;y=n;
    while (v[x-1][y]==nr)
        {
            x--;
        }
        while (v[x][y-1]==nr)
        y--;
    c[nr]=a[x];
    for (k=nr-1;k>=1;k--)
    {
        while (v[x-1][y-1]==k)
        {
            x--;
        }
        while (v[x][y-1]==k)
        y--;

        c[k]=a[x];
    }

    for (i=1;i<=nr;i++)
    printf("%d ",c[i]);

    return 0;
}
