#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,a[260],b[260],sol[260][260];

void solve(int x,int y){
    while(sol[x][y]==sol[x-1][y]) x--;
    while(sol[x][y]==sol[x][y-1]) y--;
    if(sol[x][y]>1) solve(x-1,y-1);
    printf("%d ",a[x]);
}

int main(){
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;i++) scanf("%d ",&a[i]);
    for(i=1;i<=m;i++) scanf("%d ",&b[i]);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            if(a[i]==b[j]) sol[i][j]=1+sol[i-1][j-1];
            else sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
    }
    printf("%d\n",sol[n][m]);
    solve(n,m);
}
