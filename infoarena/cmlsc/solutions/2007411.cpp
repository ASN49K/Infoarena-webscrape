#include <cstdio>
#include <algorithm>
using namespace std;
const int NMAX = 1030;
int v1[NMAX], v2[NMAX];
int d[NMAX][NMAX];
int sol[NMAX];

int main()
{
    int n, m, i, j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(i = 1;i <= n; ++i) {
        scanf("%d", &v1[i]);
    }
    for(i = 1;i <= m; ++i) {
        scanf("%d", &v2[i]);
    }
    for(i = 1;i <= n; ++i) {
        for(j = 1;j <= m; ++j) {
            if(v1[i] == v2[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    printf("%d\n", d[n][m]);
    int nr = d[n][m], top = 0;
    for(i = n;i > 0; --i) {
        for(j = m;j > 0 && i > 0; --j) {
            if(d[i][j] == nr && v1[i] == v2[j]) {
                --nr;
                sol[++top] = v1[i--];
            }
        }
    }
    while(top > 0) {
        printf("%d ", sol[top--]);
    }
    printf("\n");
    return 0;
}
