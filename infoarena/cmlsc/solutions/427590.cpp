#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

void open(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
}

short n,m,a[1030],b[1030],maxi,idxx,idxy;
short dp[1030][1030],par[1030][1030];

void find_path(short x,short y,short c){
    short idx,idy,cnxt;
    if (c==0) return;
    if (par[x][y]==0){
        idx=x-1;
        idy=y-1;
        cnxt=c-1;
        find_path(idx,idy,cnxt);
        if (c>1) printf(" ");
        printf("%d",a[x-1]);
        return;
    }
    else if (par[x][y]==1){
        idx=x;
        idy=y-1;
        cnxt=c;
    }
    else {
        idx=x-1;
        idy=y;
        cnxt=c;
    }
    find_path(idx,idy,cnxt);
}

int main(){
    open();
    scanf("%d%d",&n,&m);
    for (short i=0;i<n;i++) scanf("%d",&a[i]);
    for (short i=0;i<m;i++) scanf("%d",&b[i]);
    for (short i=1;i<=n;i++){
        for (short j=1;j<=m;j++){
            if (a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                par[i][j]=0;
            }
            else {
                if (dp[i][j-1]>dp[i-1][j]){
                    dp[i][j]=dp[i][j-1];
                    par[i][j]=1;
                }
                else {
                    dp[i][j]=dp[i-1][j];
                    par[i][j]=2;
                }
            }
            if (maxi<dp[i][j]){
                maxi=dp[i][j];idxx=i;idxy=j;
            }
        }
    }
    printf("%d\n",maxi);
    find_path(idxx,idxy,maxi);
    printf("\n");
    //system("pause");
    return 0;
}
