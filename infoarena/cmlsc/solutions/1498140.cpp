#include <cstdio>

using namespace std;

int v[1030],v1[1030],v3[1030];
int d[1025][1025];
int t[1025][1025];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int m,n,i,j,maxx=0,p=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&v1[i]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(d[i-1][j]>d[i][j-1]) {maxx=d[i-1][j];t[i][j]=1;}
            else {maxx=d[i][j-1];t[i][j]=2;}
            if(v[i]==v1[j]) if(d[i-1][j-1]+1>maxx) {maxx=d[i-1][j-1]+1;t[i][j]=3;}
            d[i][j]=maxx;
        }
    printf("%d\n",d[m][n]);
    i=m;
    j=n;
    while(i>=1 && j>=1)
        if(t[i][j]==1) i--;
        else if(t[i][j]==2) j--;
        else {v3[++p]=v[i];i--;j--;}
    for(int k=p;k>=1;k--)
        printf("%d ",v3[k]);
    return 0;
}
