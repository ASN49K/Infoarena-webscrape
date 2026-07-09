#include<cstdio>
#include<algorithm>

using namespace std;

int max(int y,int x)
{
    if(x>y)
        return x;
    return y;
}

int a[1056],b[1056],d[1056][1056],i,j,n,m,v[1056],nr;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=1;j<=m;j++)
    {
        scanf("%d",&b[j]);
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]==b[1])
        {
            d[i][1]=1;
        }
        else d[i][1]=d[i-1][1];
    }
    for(i=1;i<=m;i++)
    {
        if(a[1]==b[i])
        {
            d[1][i]=1;
        }
        else d[1][i]=d[1][i-1];
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    nr=0;
    printf("%d\n",d[n][m]);
    i=n;
    j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            nr++;
            v[nr]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]>d[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }
    reverse(v+1,v+nr+1);
    for(i=1;i<=nr;i++)
    {
        printf("%d ",v[i]);
    }
}
