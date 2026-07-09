#include <iostream>
#include <cstdio>

#define N 1030

using namespace std;

int n,m,a[N],b[N],dp[N][N];
int sol[N], len;

int solve(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    return dp[n][m];
}

void drum(int x, int y, int v){
    if(!dp[x][y])
        return ;
    if(a[x]==b[y]){
        sol[v] = a[x];
        drum(x-1,y-1,v-1);
    }else{
        if(dp[x][y-1] > dp[x-1][y])
            drum(x,y-1,v);
        else
            drum(x-1,y,v);
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d", &n,&m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);

    len = solve();
    printf("%d\n", len);
    drum(n,m,len);
    for(int i = 1; i <= len; ++i)
        printf("%d ", sol[i]);
    return 0;
}
