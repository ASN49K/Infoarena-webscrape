#include <stdio.h>
#include <algorithm>

#define maxn 100000

int n, m, x[maxn], y[maxn], lcs[maxn][maxn];

int main()
{
    freopen("cmlsc.in", "r", stdin);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
       scanf("%d", &x[i]); 
    } 

    for (int i = 0; i < m; i++) {
       scanf("%d", &y[i]); 
    } 

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
           if (x[i] == y[j])
           {
               lcs[i][j] = 1 + lcs[i-1][j-1];
           } 
           else
           {
               lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
           }
        }
    }

    printf("%d", lcs[n][m]);

    fclose(stdin);

    return 0;
}
