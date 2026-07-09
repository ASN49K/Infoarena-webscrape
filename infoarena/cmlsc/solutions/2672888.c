#include <stdio.h>
#include <stdlib.h>
int a[1024], b[1024];
int dp[1024][1024];
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
int constructie(int m, int n)
{
    int i, j;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];


}
void subsir(int l, int c)
{
    if(l==0 || c==0)
    {
        return;
    }
    if(a[l]==b[c])
    {
        subsir(l-1, c-1);
        printf("%d ", a[l]);
    }
    else
    {
        if(dp[l-1][c]>dp[l][c-1])
        {
            subsir(l-1, c);
        }
        else
        {
            subsir(l, c-1);
        }
    }
}

int main()
{
    int M, N, i, j;
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    scanf("%d%d",&M,&N);
    for(i=1; i<=M; i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=1; j<=N; j++)
    {
        scanf("%d",&b[j]);
    }
    printf("%d\n",constructie(M, N));
    subsir(M, N);
    return 0;
}
