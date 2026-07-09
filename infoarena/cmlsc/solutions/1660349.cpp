#include <cstdio>

using namespace std;

int v[1030],v1[1030],d[1030][1030],r[1030][1030],v3[1030];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,maxx=0,l=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&v1[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(d[i-1][j]>d[i][j-1]) {maxx=d[i-1][j];r[i][j]=1;}
            else {maxx=d[i][j-1];r[i][j]=2;}
            if(v[i]==v1[j]) if(d[i-1][j-1]+1>maxx) {maxx=d[i-1][j-1]+1;r[i][j]=3;}
            d[i][j]=maxx;
        }
    printf("%d\n",d[n][m]);
    int i=n;
    int j=m;
    while(i>=1 && j>=1)
    {
        if(r[i][j]==1) i--;
        else if(r[i][j]==2) j--;
        else {l++;v3[l]=v[i];i--;j--;}
    }
    for(int k=l;k>=1;k--)
        printf("%d ",v3[k]);
    return 0;
}
