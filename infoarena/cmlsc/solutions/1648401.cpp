#include<cstdio>
#include<algorithm>

using namespace std;

int n,m;
int a[1030][1030];
int v1[1030],v2[1030];
int keep[1030],sz;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v1[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&v2[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    while(sz!=a[n][m])
    {
        if(v1[i]==v2[j])
        {
            sz++;
            keep[sz]=v1[i];
            i--;
            j--;
        }
        else if(a[i-1][j]>a[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("%d\n",a[n][m]);
    for(i=a[n][m];i>0;i--)
    {
        printf("%d ",keep[i]);
    }

}
