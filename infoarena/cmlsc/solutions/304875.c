#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1030

int a[NMAX],b[NMAX],best[NMAX][NMAX];

int cautaLin(int lin,int col,int lg)
{
    int j,found=0;
    for (j=1;j<=col;j++)
    if ((best[lin][j]==lg) && (a[lin]==b[j]))
    {
        found=j;
        break;
    }
    return found;
}

int cautaCol(int lin,int col,int lg)
{
    int i,found=0;
    for (i=1;i<=lin;i++)
    if ((best[i][col]==lg) && (a[i]==b[col]))
    {
        found=i;
        break;
    }
    return found;
}

void afis(int lin,int col,int lg)
{
    int i,j,tlin,tcol;
    if (lg!=0)
    {
        j=cautaLin(lin,col,lg);
        if (j==0)
        {
            i=cautaCol(lin,col,lg);
            if (i)
            {
                tlin=i;tcol=col;
                afis(i-1,col-1,lg-1);
            }
        }
        else
        {
            tlin=lin;tcol=j;
            afis(lin-1,j-1,lg-1);
        }
        if (i==0 && j==0)
        {
            tlin=lin;tcol=col;
            afis(lin-1,col-1,lg);
        }
        if (a[tlin]==b[tcol])
            printf("%d ",a[tlin]);
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d %d",&n, &m);
    for (i=1;i<=n;i++) scanf("%d",a+i);
    for (i=1;i<=m;i++) scanf("%d",b+i);
    for (j=1;j<=m;j++)
    for (i=1;i<=n;i++)
    {
        if (a[i]==b[j])
        {
            best[i][j]=1+best[i-1][j-1];
        }
        else
        {
            if (best[i-1][j]>best[i][j-1])
            {
                best[i][j]=best[i-1][j];
            }
            else
            {
                best[i][j]=best[i][j-1];
            }
        }
    }
    printf("%d\n",best[n][m]);
    afis(n,m,best[n][m]);
    fclose(stdout);
    return 0;
}

