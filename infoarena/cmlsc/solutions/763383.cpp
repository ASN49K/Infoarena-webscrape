#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1025

int n,m,c[MAX][MAX];

class vector{
    public:
    int x[MAX];
    void get(int n){
        for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    }
}a,b;

void DP(){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a.x[i]==b.x[j]) c[i][j] = 1 + c[i-1][j-1]; else
        c[i][j] = max(c[i-1][j],c[i][j-1]);
}

void tipar(int n,int m){
    if(c[n][m]>0)
    {
        if(a.x[n]==b.x[m])
        {
            tipar(n-1,m-1);
            printf("%d ",a.x[n]);
        } else
        if(c[n-1][m]>c[n][m-1])tipar(n-1,m); else tipar(n,m-1);
    }
}

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
        scanf("%d %d",&n,&m);
        a.get(n);
        b.get(m);
    DP();
        printf("%d\n",c[n][m]);
        tipar(n,m);
 //   for(int i=1;i<=n;i++)printf("%d ",a.x[i]); printf("\n");
 //   for(int i=1;i<=m;i++)printf("%d ",b.x[i]); printf("\n");
    return 0;
}
