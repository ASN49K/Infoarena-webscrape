#include <cstdio>
using namespace std;

int n, m, d[1025][1025], Sol[1025];
int a[1025], b[1025];
inline int max(int x, int y){
    return (x > y) ? x : y;
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n ; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m ; ++i)
        scanf("%d", &b[i]);

    for(int i = 1; i <= n ; ++i)
        for(int j = 1; j <= m ; ++j)
            if(a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    printf("%d\n", d[n][m]);
    int NR = 0;
    for(int i = n, j = m; i ; ){
        if(a[i] == b[j]) Sol[++NR] = a[i--], --j;
        else if(d[i][j - 1] > d[i - 1][j]) --j;
        else --i;
    }
    for(int i = NR; i >= 1 ; --i)
        printf("%d ", Sol[i]);
    return 0;
}
