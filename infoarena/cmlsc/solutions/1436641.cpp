#include <iostream>
#include <cstdio>

using namespace std;
int m,n,i,j,a[1050][1050],v1[1050],v2[1050],x[1050],k;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (i=1; i<=m; i++) scanf("%d",&v1[i]);
    for (j=1; j<=n; j++) scanf("%d",&v2[j]);
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
        if (v1[i]==v2[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],max(a[i-1][j-1],a[i][j-1]));
    printf("%d\n",a[m][n]);
    i=m;
    j=n;
    k=0;
    while (a[i][j]>=1)
    {
        if (v1[i]==v2[j])
        {
            x[++k]=v1[i];
            i--;
            j--;
        }
        else if (a[i-1][j]==max(a[i-1][j-1],a[i][j-1])) i--;
            else if (a[i-1][j-1]==max(a[i-1][j],a[i][j-1])) { i--; j--;}
                else j--;
    }
    for (i=k; i>=1; i--) printf("%d ",x[i]);
    return 0;
}
