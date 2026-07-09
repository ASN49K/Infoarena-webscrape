#include <cstdio>
#include <algorithm>
#define Nmax 1030

using namespace std;

int dp[Nmax][Nmax],a[Nmax],b[Nmax],sol[Nmax];

int main()
{
    int N,M,i,j;
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    scanf("%d%d", &N,&M);
    for(i=1;i<=N;++i)
        scanf("%d", &a[i]);
    for(i=1;i<=M;++i)
        scanf("%d", &b[i]);
    for(i=1;i<=N;++i)
        for(j=1;j<=M;++j)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d\n", dp[N][M]);
    while(N && M)
    {
        if(a[N]==b[M])
        {
            sol[++sol[0]]=a[N];
            --N; --M;
        }
        else
            if(dp[N][M-1]>dp[N-1][M])
                --M;
            else
                --N;
    }
    for(i=sol[0];i;--i)
        printf("%d ", sol[i]);
    printf("\n");
    return 0;
}
