#include <cstdio>

using namespace std;
int v[100][100],a[100],b[100],sol[100];
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
                v[i][j]=max(max(v[i][j],v[i-1][j]),v[i][j-1])+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    printf("%d\n",v[n][m]);
    int t=0;
    while(n&&m)
    {
        if(a[n]==b[m])
        {
            sol[++t]=a[n];
            n--;m--;
        }

        if(v[n-1][m]>v[n][m-1])
            if(v[n-1][m]>v[n-1][m-1])
                n--;
            else
                n--,m--;
        else
            if(v[n][m-1]>v[n-1][m-1])
                m--;
            else
                n--,m--;
    }
    for(i=t;i>=1;i--)
        printf("%d ",sol[i]);
    return 0;
}
