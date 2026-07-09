#include <cstdio>
#include<algorithm>
using namespace std;
int cm[1026][1026],a[1026],b[1026],v[1026];
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
    i=n;
    j=m;
    printf("%d\n",cm[n][m]);
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j])v[x]=a[i],x++,i--,j--;
        else if(cm[i-1][j]==cm[i][j])i--;
             else j--;
    }
    for(i=cm[n][m];i>=1;i--)
        printf("%d ",v[i]);
    return 0;
}
