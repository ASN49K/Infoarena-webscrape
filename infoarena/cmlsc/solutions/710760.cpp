#include <stdio.h>
struct sir{
    int x[1025];
    void get(int n){ for(int i=1;i<=n;i++)scanf("%d",&x[i]); }
}a,b;

int d[1025][1025],n,m;

inline int max(int a,int b){ return a>b?a:b; }
void dp(){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a.x[i]==b.x[j])d[i][j]=1+d[i-1][j-1]; else
        d[i][j]=max(d[i-1][j],d[i][j-1]); }

void pt(int i,int j){
    if(d[i][j]>0){
        if(a.x[i]==b.x[j]){
            pt(i-1,j-1);
            printf("%d ",a.x[i]); } else
        if(d[i-1][j]>d[i][j-1])pt(i-1,j); else pt(i,j-1); }
}

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
        scanf("%d %d",&n,&m);
        a.get(n);
        b.get(m);
        dp();
    printf("%d\n",d[n][m]);
    pt(n,m);
}
