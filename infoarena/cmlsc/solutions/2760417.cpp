#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1024;

int n,m;
int a[NMAX];
int b[NMAX];
int dp[NMAX][NMAX];

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    vector<int> sol;
    int x = n, y = m;
    while (x && y) {
        if (a[x] == b[y]) {
            sol.push_back(a[x]);
            x--;
            y--;
        } else if(dp[x][y] == dp[x][y-1]){
            y--;
        }else{
            x--;
        }
    }
    for (int i = sol.size() - 1; i >= 0; i--)printf("%d ", sol[i]);


    return 0;
}


