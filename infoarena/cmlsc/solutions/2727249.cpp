#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1024;

int a[NMAX + 1], b[NMAX + 1], al, bl, dp[NMAX + 1][NMAX + 1];
stack<int> reconstr;

void generReconstr() {
    int x = al, y = bl;
    while(x && y) {
        if(a[x] == b[y]) reconstr.push(a[x]), --x, --y;
        else if(dp[x - 1][y] == dp[x][y]) --x;
        else --y;
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &al, &bl);
    for(int i = 1; i <= al; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= bl; ++i) scanf("%d", &b[i]);
    for(int i = 1; i <= al; ++i)
        for(int j = 1; j <= bl; ++j)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    printf("%d\n", dp[al][bl]);
    generReconstr();
    while(!reconstr.empty()) printf("%d ", reconstr.top()), reconstr.pop();
    return 0;
}
