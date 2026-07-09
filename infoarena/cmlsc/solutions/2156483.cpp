#include <stdio.h>
#include <iostream>
using namespace std;
int n,m,v1[1025],v2[1025],a[1025][1025],nr,SIR_SEPARAT[1025];
int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    scanf("%d %d",&m,&n);
    for(int i=1; i<=m; ++i)
        scanf("%d",&v1[i]);
    for(int i=1; i<=n; ++i)
        scanf("%d",&v2[i]);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(v1[j]==v2[i])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    printf("%d\n",a[n][m]);
    for(int i=n,j=m; i>=1;)
    {
        if(v1[j]==v2[i])
        {
            SIR_SEPARAT[++nr]=v1[j];
            --i;
            --j;
        }
        else if(a[i-1][j]<a[i][j-1])
        {
            --j;
        }
        else --i;
    }
    for(int i=nr;i>=1;--i)
        printf("%d ",SIR_SEPARAT[i]);
    return 0;
}
