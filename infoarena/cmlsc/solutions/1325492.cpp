#include <cstdio>

using namespace std;
int v[1030][1034],a[1034],b[1034],sol[1034];
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    printf("%d\n",v[n][m]);
    int t=0;
    while(n>0&&m>0)
    {
        if(a[n]==b[m])
        {
            sol[++t]=a[n];
            n--;m--;
        }
        else
            if(v[n][m-1]>v[n-1][m])
                m--;
            else
                n--;

    }
    for(i=t;i>=1;i--)
        printf("%d ",sol[i]);
    return 0;
}
