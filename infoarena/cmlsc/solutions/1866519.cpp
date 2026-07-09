#include <cstdio>
#define MAX(A, B) A >= B? A : B
#define NMAX 1025
using namespace std;

FILE *f = freopen("cmlsc.in", "r", stdin);
FILE *g = freopen("cmlsc.out", "w", stdout);
int A[NMAX], B[NMAX];
int dp[NMAX][NMAX], n, m, rez[NMAX];
void read() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++)
        scanf("%d", &A[i]);
    for(int i = 1; i<=m; i++)
        scanf("%d", &B[i]);
}
void cmlsc() {
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            if(A[i] == B[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
    else dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
}
void trace() {
    int sol = dp[n][m];
    int i = n, j = m;
    while(sol) {
        if(dp[i - 1][j] == sol)
            i --;
        else if(dp[i][j - 1] == sol)
            j --;
        else {
            rez[sol] = A[i];
            i --;
            j --;
            sol--;
        }
    }
    printf("%d\n", dp[n][m]);
    for(int i = 1; i<=dp[n][m]; i++)
        printf("%d ", rez[i]);
}
int main() {
    read();
    cmlsc();
    trace();
    //printf("%d", dp[n][m]);
    return 0;
}
