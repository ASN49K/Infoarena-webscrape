#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1025;

int n, m, i, j, k, a[maxn], b[maxn], answer[maxn], v[maxn][maxn];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(i=1; i<=m; ++i) scanf("%d", &b[i]);

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j], v[i][j-1]);

    for(i=n, j=m; i; )
        if(a[i]==b[j])
        {
            answer[++k]=a[i];
            --i;
            --j;
        }
        else if(v[i-1][j]>v[i][j-1]) --i;
             else --j;

    printf("%d\n", k);
    for(; k; --k) printf("%d ", answer[k]);

    return 0;
}
