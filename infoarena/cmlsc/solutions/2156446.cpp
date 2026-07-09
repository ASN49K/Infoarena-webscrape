#include <stdio.h>
#include <iostream>
using namespace std;
int n,m,v1[1025],v2[1025],a[1025][1025];
int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;++i)
        scanf("%d",&v1[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&v2[i]);

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(v1[j]==v2[i])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    printf("%d\n",a[n][m]);
    return 0;
}
