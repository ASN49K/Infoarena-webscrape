#include <cstdio>
using namespace std;
int x[1025], y[1025], mat[1025][1025], sol[1025];
int max1(int a, int b){
    if (a < b)
        return b;
    return a;
}
int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m, i, j, l, c, maxim, cop;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i ++)
        scanf("%d", &x[i]);
    for (i = 1; i <= m; i ++)
        scanf("%d", &y[i]);
    for (i = 1; i <= n; i ++)
        for (j = 1; j <= m; j ++)
            if (x[i] == y[j])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = max1(mat[i - 1][j], mat[i][j - 1]);
    i = n; j = m;
    maxim = 0;
    while (i > 0 && j > 0){
        if (x[i] == y[j]){
            sol[++maxim] = x[i];
            i --;
            j --;
        }
        else if (mat[i - 1][j] < mat[i][j - 1])
            j --;
        else
            i --;
    }
    printf("%d\n", maxim);
    for (i = maxim; i >= 1; i --)
        printf("%d ", sol[i]);
    return 0;
}
