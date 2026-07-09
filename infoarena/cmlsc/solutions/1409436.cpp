#include <cstdio>
#include <algorithm>
using namespace std;
const int NMAX = 1030;
int dp[NMAX][NMAX], sol[NMAX], n , m, a[NMAX] , b[NMAX];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d ",&a[i]);
    for(int j=1;j<=m;++j)
        scanf("%d ",&b[j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i] == b[j])
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    int i=n,j=m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            sol[++sol[0]] = a[i];
            --i,--j;
        }
        else
            if(dp[i-1][j] > dp[i][j-1])
                --i;
            else
                --j;
    }
    reverse(sol+1,sol+sol[0]+1);
    printf("%d\n",sol[0]);
    for(int i=1;i<=sol[0];++i)
        printf("%d ",sol[i]);
    return 0;
}
