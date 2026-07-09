#include <stdio.h>
#include <stdlib.h>
#define NMAX 1024

int a[NMAX],b[NMAX],dp[NMAX][NMAX];

int max(int x, int y)
{
    if(x>y)
    {
        return x;
    }
    return y;
}
int constr (int n, int m)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j] = 1+ dp[i-1][j-1];

            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
void subsir (int l,int c)
{
    if(l==0 || c==0)
    {
        return;
    }
    if(a[l]==b[c])
    {
        subsir(l-1,c-1);
        printf ("%d ",a[l]);
    }
    else
    {
        if(dp[l-1][c] > dp[l][c-1])
        {
            subsir(l-1,c);
        }
        else
        {
            subsir(l,c-1);
        }
    }
}

int main()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    int i,n,m,j,f;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
    }

    printf("%d\n",constr(n,m));
    subsir(n,m);

    return 0;
}
