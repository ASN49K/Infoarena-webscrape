#include <cstdio>
#include<algorithm>
using namespace std;
int cm[1026][1026],a[1026],b[1026];
int main()
{
    int n,m,i,j,x;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])cm[i][j]=cm[i-1][j-1]+1;
            else cm[i][j]=max(cm[i-1][j],cm[i][j-1]);
        }
    x=1;
    printf("%d\n",cm[n][m]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(cm[i][j]==x)
            {
                printf("%d ",a[i]);
                x++;
            }
    return 0;
}
