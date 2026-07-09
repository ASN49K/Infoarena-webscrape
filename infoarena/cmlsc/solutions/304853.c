#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1025

int a[NMAX],b[NMAX],best[NMAX][NMAX],plin[NMAX][NMAX],pcol[NMAX][NMAX];

void afis(int lin,int col)
{
    if (best[lin][col]!=0)
    {
        afis(plin[lin][col],pcol[lin][col]);
        if (a[lin]==b[col])
            printf("%d ",a[lin]);
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d %d",&n, &m);
    for (i=1;i<=n;i++) scanf("%d",a+i);
    for (i=1;i<=n;i++) scanf("%d",b+i);
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
        if (a[i]==b[j])
        {
            best[i][j]=1+best[i-1][j-1];
            plin[i][j]=i-1;pcol[i][j]=j-1;
        }
        else
        {
            if (best[i-1][j]>best[i][j-1])
            {
                best[i][j]=best[i-1][j];
                plin[i][j]=i-1;pcol[i][j]=j;
            }
            else
            {
                best[i][j]=best[i][j-1];
                plin[i][j]=i;pcol[i][j]=j-1;
            }
        }
    }
    printf("%d\n",best[n][m]);
    afis(n,m);
    fclose(stdout);
    return 0;
}

