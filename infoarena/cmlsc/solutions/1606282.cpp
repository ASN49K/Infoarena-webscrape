#include <stdio.h>
#define MAX(a, b) (a < b ? b : a)
#define N_MAX 1026

int n, m;
short s1[N_MAX], s2[N_MAX];
short best[N_MAX][N_MAX];
short sol[N_MAX];
short nr;

inline void citire();

int main()
{
    citire();
    int i, j;

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            if (s1[i] == s2[j])
                best[i][j] = 1 + best[i-1][j-1];
            else
                best[i][j] = MAX(best[i-1][j], best[i][j-1]);

    i = n; j = m;
    while (i != 0){
        if (s1[i] == s2[j]){
            sol[++nr] = s1[i];
            i--; j--;
        } else if (best[i][j-1] > best[i-1][j]){
            j--;
        } else {
            i--;
        }
    }
    printf("%d\n", nr);
    for (i = nr; i > 0; --i)
        printf("%hd ", *(sol+i));
    printf("\n");

    return 0;
}

inline void citire(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);

    int i;
    for (i = 1; i <= n; ++i) scanf("%hd", s1+i);
    for (i = 1; i <= m; ++i) scanf("%hd", s2+i);
}
