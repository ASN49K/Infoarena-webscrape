#include <bits/stdc++.h>
using namespace std;
#define LMAX 1030
int v[LMAX],u[LMAX];
int dp[LMAX][LMAX];
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    for(int i=1;i<=m;++i)
        scanf("%d",&u[i]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(v[i]==u[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d\n",dp[n][m]);
    int i=n,j=m;
    stack<int> ans;
    while(i>0&&j>0){
        if(v[i]==u[j]){
            ans.push(v[i]);
            --i;--j;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            --i;
        else --j;
    }
    while(!ans.empty()){
        printf("%d ",ans.top());
        ans.pop();
    }
    return 0;
}
