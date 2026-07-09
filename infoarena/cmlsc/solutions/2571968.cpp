#include<bits/stdc++.h>
using namespace std;

const int NMAX=1030;

int a[NMAX],b[NMAX];
int dp[NMAX][NMAX],subsir_comun[NMAX*2];

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d", &b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    int cnt=0;
    for(int i=n,j=m;i;)
        if(a[i]==b[j]){
            subsir_comun[++cnt]=a[i];
            i--,j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else i--;
    printf("%d\n", cnt);
    for(int i=cnt;i>=1;i--)
        printf("%d ", subsir_comun[i]);
    return 0;
}
