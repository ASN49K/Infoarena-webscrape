#include <cstdio>

using namespace std;
int i,j,n,m,a[500],b[500],c[500][500],maxi,x,d[500],k;
int maxim(int x,int y)
{
    if(x>y) return x;
    else return y;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(i=1; i<=m; ++i) scanf("%d",&b[i]);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=maxim(c[i-1][j],c[i][j-1]);
            if(c[i][j]>maxi)maxi=c[i][j];
        }
    printf("%d\n",maxi);
    for(i=n; i>=1; i--)
    {
        for(j=m; j>=1; j--)
            if(a[i]==b[j]&&c[i][j]==maxi)
            {
                d[maxi]=a[i];
                k++;
                maxi--;
            }
    }
    for(i=1; i<=k; ++i)
    {
        printf("%d ",d[i]);
    }
    return 0;
}
