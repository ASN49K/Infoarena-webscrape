#include<stdio.h>
#include<algorithm>
using namespace std;
short n,m; unsigned char a[1030],b[1030],sol[1030][1030];

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
    scanf("%hd %hd\n",&n,&m);
    for(i=1;i<=n;i++) scanf("%d ",(int*)&a[i]);
    for(i=1;i<=m;i++) scanf("%d ",(int*)&b[i]);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            if(a[i]==b[j]) sol[i][j]=1+sol[i-1][j-1];
            else sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
    }
    printf("%d\n",(int)sol[n][m]);
    solve(n,m);
}
