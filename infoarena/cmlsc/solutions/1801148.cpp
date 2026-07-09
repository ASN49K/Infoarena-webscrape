#include <cstdio>
#define max(a, b) ((a > b) ? a : b)

using namespace std;

int mat[1025][1025], mutal[1025];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int m, n, a[1025], b[1025], k=0;
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) scanf("%d", &b[i]);

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i] == b[j]) mat[i][j] = mat[i-1][j-1]+1;
            else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }
    for(int i=m, j=n; i;)
    {
        if(a[i] == b[j])
        {
            mutal[++k]=a[i];
            i--;
            j--;
        }
        else if(mat[i-1][j] < mat[i][j-1]) j--;
        else i--;
    }
    printf("%d\n", k);
    for(int i=k; i>0; i--)
        printf("%d ", mutal[i]);
}
