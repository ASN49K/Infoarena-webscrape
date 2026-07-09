#include <iostream>
#include <cstdio>
using namespace std;
int dp[1025][1025], a[1025], b[1025], m, n, lm;
int f[1025],k;
void lungimi()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            lm=max(lm, dp[i][j]);
        }
    }
}
void afisare(int i, int j)
{
    if(dp[i][j]==0)
        return ;
    if(a[i]==b[j])
    {
        f[k]=a[i];
        k++;
        afisare(i-1,j-1);
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1])
            afisare(i-1,j);
        else
            afisare(i,j-1);
    }
}
void scriere()
{
    for(int i=k-1;i>=0;i--)
        printf("%d ", f[i]);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d\n", &m, &n);
    for(int i=1;i<m;i++)
    {
        scanf("%d ", &a[i]);
    }
    scanf("%d\n", &a[m]);
    for(int i=1;i<n;i++)
    {
        scanf("%d ", &b[i]);
    }
    scanf("%d\n", &b[n]);
    lungimi();
    printf("%d\n", lm);
    afisare(m,n);
    scriere();
    return 0;
}
