#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

#define N 1030

int q[N][N];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j,k=0,a[N],b[N],z[N],n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(j=1;j<=m;j++)
        scanf("%d",&b[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                q[i][j]=q[i-1][j-1]+1;
            else
            {
                q[i][j]=max(q[i][j-1],q[i-1][j]);
            }
        }
    printf("%d\n",q[n][m]);

    i=n;
    j=m;
    for(;i>0&&j>0;)
    {
        if(a[i]==b[j])
        {
            z[k++]=a[i];
            i--;
            j--;
        }
        else if(q[i-1][j]<q[i][j-1])
            --j;
        else
            --i;
    }
    for(i=k-1;i>=0;i--)
        printf("%d ",z[i]);
    return 0;
}
