#include <bits/stdc++.h>
using namespace std;
int v[1025],u[1025],sol[1025],DP[1025][1025];
struct Point{
    int l,c;
};
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
                DP[i][j]=DP[i-1][j-1]+1;
            else DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
    printf("%d\n",DP[n][m]);
    Point poz={n,m};
    int ct=0;
    while(poz.l>0&&poz.c>0){
        while(poz.c>1&&DP[poz.l][poz.c]==DP[poz.l][poz.c-1])
            --poz.c;
        while(poz.l>1&&DP[poz.l][poz.c]==DP[poz.l-1][poz.c])
            --poz.l;
        sol[DP[n][m]-(ct++)]=v[poz.l];
        --poz.l;--poz.c;
    }
    for(int i=1;i<=DP[n][m];++i)
        printf("%d ",sol[i]);
    return 0;
}
