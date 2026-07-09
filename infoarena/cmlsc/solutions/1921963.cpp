#include <stdio.h>
#include <algorithm>
using namespace std;
int v1[1025], v2[1025], a[1025][1025];
void subsir(int i, int j)
{
    if(i != 0 && j != 0)
        if(v1[i] == v2[j]) {
            subsir(i-1,j-1);
            printf("%d ",v1[i]);
        }
        else
            if(a[i-1][j] > a[i][j-1])
                subsir(i-1,j);
            else
                subsir(i,j-1);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n, m, i, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&v1[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&v2[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) {
            if(v1[i] == v2[j]) {
                a[i][j] = a[i-1][j-1] + 1;
            }
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
        }
    printf("%d\n",a[n][m]);
    subsir(n,m);
    return 0;
}
