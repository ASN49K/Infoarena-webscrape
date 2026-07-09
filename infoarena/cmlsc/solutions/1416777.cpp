#include <cstdio>
#include <algorithm>
#define Dim 1025

using namespace std;
int n,m,i,j,a[Dim],b[Dim],c[Dim][Dim],d[Dim],k;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    /// citire
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    scanf("%d",&b[i]);

    /// comun
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
        c[i][j]=1+c[i-1][j-1];
        else
        c[i][j]=max(c[i][j-1],c[i-1][j]);
    }

    ///sir
    k=0;
    i=n;
    j=m;
    while(c[i][j]!=0)
    if(a[i]==b[j])
    {
        d[++k]=a[i];
        i--;
        j--;
    }
    else
    if(c[i][j]==c[i-1][j]) i--;
    else j--;
    printf("%d\n",c[n][m]);
    for(i=k;i>=1;i--)
    printf("%d ",d[i]);




    return 0;
}
