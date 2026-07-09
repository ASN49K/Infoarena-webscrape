#include <cstdio>
using namespace std;
int v[1025],w[1025],a[1025][1025],sir[1025];
int maxi(int a,int b)
{
    if (a>b)return a;
    else return b;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j,n,m,nr=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&v[i]);
    for(i=1;i<=m;i++)scanf("%d",&w[i]);
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
    {
        if(v[i]==w[j])a[i][j]=a[i-1][j-1]+1;
        else a[i][j]=maxi(a[i-1][j],a[i][j-1]);

    }
    i=n;j=m;
    while(i)
    {
        if(v[i]==w[j]){sir[++nr]=v[i];i--;j--;}
        else if(a[i-1][j]<a[i][j-1])j--;
        else i--;
    }
    printf("%d\n",nr);
    for(i=nr;i>=1;i--)printf("%d ",sir[i]);
    return 0;
}
