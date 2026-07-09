#include <bits/stdc++.h>

using namespace std;

#define fin stdin
#define fout stdout

#define MAX 1025

int v1[MAX], v2[MAX], dp[MAX][MAX];
int sol[MAX];

int main()  {
    freopen("cmlsc.in", "r", fin);
    freopen("cmlsc.out", "w", fout);
    int M, N;
    scanf("%d%d", &M, &N);
    int ind = 0, i, j;
    for(i = 1;i <= M;i++)
        scanf("%d", &v1[i]);
    for(i = 1;i <= N;i++)
        scanf("%d", &v2[i]);
    for(i = 1;i <= M;i++)
        for(int j = 1;j <= N;j++)  {
            if(v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    for(i = M, j = N;i > 0, j > 0;)  {
        if(v1[i] == v2[j])
            sol[ind++] = v1[i], i--, j--;
        else  {
            if(dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    printf("%d\n", ind);
    for(i = ind - 1;i >= 0;i--)
        printf("%d ", sol[i]);
    return 0;
}
