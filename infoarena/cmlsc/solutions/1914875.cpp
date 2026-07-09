#include <cstdio>
#include<algorithm>
using namespace std;
int i,j,n,m;
int a[1100],b[1100],sir[1100],M[1100][1100];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                M[i][j]=M[i-1][j-1]+1;
            else M[i][j]=max(M[i][j-1],M[i-1][j]);

    for(i=n,j=m;i;)
        if(a[i]==b[j])
            sir[++sir[0]]=a[i],i--,j--;
        else if(M[i-1][j]<M[i][j-1])
            j--;
        else i--;
    printf("%d\n",sir[0]);
    for(i=sir[0];i;i--)
        printf("%d ",sir[i]);

    return 0;
}
