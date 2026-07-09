#include <cstdio>
#include<algorithm>
using namespace std;
const int nm=1040;
int a[nm],b[nm],d[nm][nm],sir[nm],bst=0;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            sir[++bst]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    }
    printf("%d\n",bst);
    for(i=bst;i;i--)
        printf("%d ",sir[i]);
}
