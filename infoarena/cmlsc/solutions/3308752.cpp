#include <algorithm>
#include <vector>
#include<cstdio>
using  namespace  std;

const int NMAX = 1024;

int dp[NMAX+1][NMAX+1],a[NMAX+1],b[NMAX+1];

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    printf("%d\n",dp[n][m]);
     i=n;
     j=m;
    vector<int> lcs;
    while (i>0 && j>0) {
        if (a[i] == b[j]) {
            lcs.push_back(a[i]);
            i--;
            j--;
        }
        else if (dp[i-1][j] == dp[i][j]) {
            i--;
        }
        else {
            j--;
        }

    }
    reverse(lcs.begin(), lcs.end());

    for (auto element:lcs) {
        printf("%d ",element);
    }
    return 0;
}