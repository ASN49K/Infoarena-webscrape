#include <cstdio>
#include <algorithm>

using namespace std;
int n, m;
int dp[1030][1030], a[1030],b[1030], sol[1024];
void completare()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}
void afisare()
{
    printf("%d\n", dp[n][m]);
    int i=n, j=m, counter=0;
    while(dp[i][j]!=0)
    {
        if(a[i]==b[j])
        {
            sol[counter++]=a[i];
            i--;
            j--;

        }
        else
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
    }
    for(int x=counter-1; x>=0; x--)
        printf("%d ", sol[x]);
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=m; i++)
        scanf("%d",&b[i]);
    completare();
    afisare();

    return 0;
}
