#include <cstdio>

using namespace std;
int c[1025][1025],a[1025],b[1025],i,j,n,m,val[1025],nr;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
         if(a[i]==b[j])
            c[i][j]=c[i-1][j-1]+1;
         else
         {
             if(c[i][j-1]>c[i-1][j])
                c[i][j]=c[i][j-1];
             else
                c[i][j]=c[i-1][j];
         }
    printf("%d\n",c[m][n]);
    i=m;
    j=n;
    nr=0;
    while(i>=1&&j>=1)
        if(a[i]==b[j])
    {
        nr++;
        val[nr]=a[i];
        i--;
        j--;
    }
       else
        if(c[i][j-1]>c[i-1][j])
        j--;
       else
        i--;
    for(i=nr;i>=1;i--)
            printf("%d ",val[i]);


    return 0;
}
