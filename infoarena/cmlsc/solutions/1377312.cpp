#include <cstdio>
#include <algorithm>
#include <vector>

#define NMAX 1027

using namespace std;

int n, m;
int a[NMAX], b[NMAX], Dp[NMAX][NMAX];
vector < int > Ans;

int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int j = 1; j <= m; ++j)
        scanf("%d", &b[j]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                Dp[i][j] = Dp[i - 1][j - 1] + 1;
            else
                Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
    printf("%d\n", Dp[n][m]);
    int x = n, y = m;
    while(1){
        if(x == 0 || y == 0)
            break;
        if(a[x] == b[y]){
            --x;
            --y;
            Ans.push_back(a[x + 1]);
        }
        else
            if(Dp[x - 1][y] < Dp[x][y - 1])
                --y;
            else
                --x;
    }
    for(int i = Ans.size() - 1; i >= 0; --i)
        printf("%d ", Ans[i]);
    return 0;
}
