#include<stdio.h>
#include<algorithm>
using namespace std;
int maxl[1025][1025],sir[1025];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,a[1025],b[1025],n,m,j,d=1;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            maxl[i][j]=maxl[i-1][j-1]+1;
            else
            maxl[i][j]=max(maxl[i-1][j],maxl[i][j-1]);
        }
    }
    printf("%d\n",maxl[m][n]);
    i=m;j=n;
    while(i!=0)
    {
        if(a[i]==b[j])
        {
            sir[d]=a[i];
            d++;
            i--;
            j--;
        }
        else
        if(maxl[i-1][j]<maxl[i][j-1])
        j--;
        else
        i--;
    }
    d--;
    for(i=d;i>=1;i--)
    printf("%d ",sir[i]);
    return 0;
}
