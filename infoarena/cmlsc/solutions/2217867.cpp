#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int NMAX = 1050;
int dp[NMAX][NMAX];
int a[NMAX],b[NMAX];
int n , m;

inline bool inMatrix(int x,int y)
{
    if(x >= 1 && x <= m && y >= 1 && y <= n)
        return true;
    return false;
}

void recon(int x,int y)
{
    if(x == 0 || y == 0)
        return;
    if(a[x] == b[y])
    {
        if(inMatrix(x-1,y-1))
        recon(x-1,y-1);
        printf("%d ",a[x]);
    }
    else
        if(a[x] > b[y]){
            if(inMatrix(x-1,y))
            recon(x-1,y);
            else
            recon(x,y-1);
            }
        else{
            if(inMatrix(x,y-1))
            recon(x,y-1);
            else
            recon(x-1,y);
        }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i = 1 ; i <= m ; i++)
        scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; i++)
        scanf("%d",&b[i]);
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= m ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    printf("%d\n",dp[m][n]);
    recon(m,n);
    return 0;
}
