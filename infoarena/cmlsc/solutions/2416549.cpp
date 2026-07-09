#include <stdio.h>
int max(int a, int b){return a>b? a : b;}
int main(){

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n,m; scanf("%d %d", &n,&m);
    int arr1[n], arr2[m];
    for(int i=0; i<n; ++i) scanf("%d", &arr1[i]);
    for(int i=0; i<m; ++i) scanf("%d", &arr2[i]);

    int dp[n+1][m+1];

    for(int i=0; i<=n; ++i){
        for(int j=0; j<=m; ++j){
            if(!i || !j)
                dp[i][j]=0;
            else if(arr1[i-1]==arr2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int sol[max(n,m)]; int i=n, j=m,pos=0;
    while(i>0 && j>0){
        if(arr1[i-1]==arr2[j-1])
        {
            sol[pos++]=arr1[i-1]; i--; j--;
        }
        else if(dp[i][j-1] > dp[i-1][j])
            j--;
        else
            i--;
    }
    printf("%d\n", pos);
    for(int i=pos-1; i>=0; --i)
        printf("%d ", sol[i]);

    return 0;
}