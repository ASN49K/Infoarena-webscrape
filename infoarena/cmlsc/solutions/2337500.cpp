#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int dp[1026][1026];
int a[1026], b[1026];
int kk, k[1026];

void citire(){

    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int j=1; j<=m; ++j)
        scanf("%d",&b[j]);
}

void formDP(){

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j){

            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(max(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
        }

    printf("%d\n",dp[n][m]);
}

void makePath(){

    int i=n, j=m;
    while(dp[i][j]>=0 && i>=0 && j>=0){

        if(a[i]==b[j]){

            k[++kk]=a[i];
            i--;
            j--;
        }
        else{

            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else j--;
        }
    }

    for(int i=kk; i>=1; i--)
        printf("%d ",k[i]);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n, &m);

    citire();
    formDP();
    makePath();
    return 0;
}
