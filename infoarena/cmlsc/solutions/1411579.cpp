#include<cstdio>
#include<algorithm>

using namespace std;

int a[1001],b[1001],i,n,m,v[1001],nr,j,d[1001][1001];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(b[1]==a[i])
        {
            d[i][1]=1;
        }
        else
        {
            d[i][1]=d[i-1][1];
        }
    }
    for(i=1;i<=m;i++)
    {
        if(b[i]==a[1])
        {
            d[1][i]=1;
        }
        else
        {
            d[1][i]=d[1][i-1];
        }
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    printf("%d\n",d[n][m]);
    i=n;
    j=m;
    while(j&&i)
    {
        if(a[i]==b[j])
        {
            v[++nr]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i][j-1]>d[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    for(i=nr;i>=1;i--)
    {
        printf("%d ",v[i]);
    }
    return 0;
}
