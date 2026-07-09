#include<cstdio>
using namespace std;
int n,m,d[1024][1024],i,j,val,lin,col;
int v1[1025],v2[1025],v[1025];

int max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&v1[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&v2[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(v1[i]==v2[j])
                d[i][j]=max(d[i][j],d[i-1][j-1]+1);
        }
    printf("%d\n",d[n][m]);
    val=d[n][m];
    lin=n;
    col=m;
    while(val>0){
        if(d[lin][col]==d[lin-1][col-1]+1){
            v[val]=v1[lin];
            lin--;
            col--;
            val--;
        }
        else
        if(d[lin][col]==d[lin-1][col]){
            lin--;
        }
        else
            col--;
    }
    for(i=1;i<=d[n][m];i++)
        printf("%d ",v[i]);
    return 0;
}
