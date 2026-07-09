#include <cstdio>
#include <algorithm>
using namespace std;
int m, n, a[1025], b[1025], i, j, l[1025][1025], k, v[1024];
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &m, &n);
    for(i=1;i<=m;i++)
        scanf("%d", &a[i]);
    for(i=1;i<=n;i++)
        scanf("%d", &b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                l[i][j]=l[i-1][j-1]+1;
            else l[i][j]=max(l[i-1][j], l[i][j-1]);

    printf("%d\n", l[m][n]);
    i=m; j=n;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j])
        {
            v[k++]=a[i];
            i--; j--;
        }
        else if(l[i-1][j]>l[i][j-1])
            i--;
        else
            j--;
    }
    for(i=k-1;i>=0;i--)
        printf("%d ", v[i]);
    return 0;
}
