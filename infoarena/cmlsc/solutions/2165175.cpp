#include <cstdio>
#include <algorithm>
using namespace std;

int n,  m, i, j,v[1025], k, a[1025], b[1025], l[1025][1025];

int main ()
{

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (i=1; i<=n; i++) scanf("%d", &a[i]);
    for (i=1; i<=m; i++) scanf("%d", &b[i]);

    for (i=1; i<=n; i++){
        for (j=1; j<=m; j++){
            if (a[i]==b[j]) l[i][j]=l[i-1][j-1]+1;
            if (a[i]!=b[j]) l[i][j]=max(l[i-1][j], l[i][j-1]);
        }
    }

    printf("%d\n", l[n][m]);

    i=n; j=m;
    while (i){
        if (a[i]==b[j]){
            v[++k]=a[i];
            i--;
            j--;
        }
        else if (l[i-1][j]<l[i][j-1]) j--;
        else i--;
    }
    for (i=k; i>0; i--) printf("%d ", v[i]);
    return 0;
}
