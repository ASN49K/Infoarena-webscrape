#include<cstdio>
#include<algorithm>

using namespace std;
const int nmax=1050;
int a[nmax],b[nmax],sir[nmax],d[nmax][nmax],bst=0,n,m;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j;
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
                d[i][j]=1+d[i-1][j-1];
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
        else if(d[i][j-1]>d[i-1][j])
            j--;
        else
            i--;
    }
    printf("%d\n",bst);
    for(i=bst;i;i--)
        printf("%d ",sir[i]);
}
