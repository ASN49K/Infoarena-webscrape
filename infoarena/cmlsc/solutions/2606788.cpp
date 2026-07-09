#include <cstdio>
#define max(a, b) ((a > b) ? a : b)

int M[1025][1025];

int main() {
    int n, m, A[1025], B[1025], sol[1025], cnt = 0, i, j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for(i = 1; i <= m; ++i)
        scanf("%d", &B[i]);

    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
            if(A[i] == B[j])
                M[i][j] = M[i-1][j-1] + 1;
            else
                M[i][j] = max(M[i-1][j], M[i][j-1]);

    printf("%d\n", M[n][m]);

    i = n, j = m;
    while(i && j)
        if(A[i] == B[j]) {
            sol[++cnt] = A[i];
            --i;
            --j;
        }
        else if(M[i-1][j] > M[i][j-1])
            --i;
        else
            --j;

    for(i = cnt; i >= 1; --i)
        printf("%d ", sol[i]);
}
