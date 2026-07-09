#include <cstdio>
#include <algorithm>

using namespace std;

int d[1030][1030],v1[1030],v2[1030],sol[1030];

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int n,m,nr=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&v1[i]);
    for(int i=1;i<=m;i++) scanf("%d",&v2[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=max(d[i-1][j],max(d[i][j-1],d[i-1][j-1]+(v1[i]==v2[j])));
    for(int i=n,j=m;i && j;)
        if(d[i][j]==d[i-1][j]) i--;
        else if(d[i][j]==d[i][j-1]) j--;
        else {sol[++nr]=v1[i];i--;j--;}
    printf("%d\n",nr);
    for(int i=nr;i;i--) printf("%d ",sol[i]);
    return 0;
}
