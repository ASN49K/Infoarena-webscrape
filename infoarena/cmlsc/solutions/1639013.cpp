#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 1025;

int n,m,a[N],b[N],c[N],nc,d[N][N];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=n;j=m;
    while(i)
    {
        if(a[i]==b[j])
            c[++nc]=a[i],i--,j--;
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    }
    printf("%d\n",nc);
    for(i=nc;i>0;i--)
        printf("%d ",c[i]);
    return 0;
}
