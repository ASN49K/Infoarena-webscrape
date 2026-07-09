#include<cstdio>
using namespace std;
int a[1030];
int b[1030];
int d[1030][1030];
int r[1030];
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
    int n,m,i,j,s=0;
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
        for(j=1;j<=m;j++)
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
    for(i=n,j=m;i!=0&&j!=0;i--,j--)
    {
        if(a[i]==b[j])
        {
            r[++s]=a[i];
        }
        else
        {
            if(d[i-1][j]>d[i][j-1])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    for(i=s;i>=1;i--)
    {
        printf("%d ",r[i]);
    }
    return 0;
}
