/*
                `-/oo+/-   ``
              .oyhhhhhhyo.`od
             +hhhhyyoooos. h/
            +hhyso++oosy- /s
           .yoooossyyo:``-y`
            ..----.` ``.-/+:.`
                   `````..-::/.
                  `..```.-::///`
                 `-.....--::::/:
                `.......--::////:
               `...`....---:::://:
             `......``..--:::::///:`
            `---.......--:::::////+/`
            ----------::::::/::///++:
            ----:---:::::///////////:`
            .----::::::////////////:-`
            `----::::::::::/::::::::-
             `.-----:::::::::::::::-
               ...----:::::::::/:-`
                 `.---::/+osss+:`
                   ``.:://///-.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>

using namespace std;

const int INF = 2e9;
const int N = 1024;

int dp[5 + N][5 + N];
int v1[5 + N], v2[5 + N];
int sol[5 + N];

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) scanf("%d", &v1[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &v2[i]);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    printf("%d\n", dp[n][m]);
    for(int i = n, j = m; i > 0 && j > 0;) {
        if(v1[i] == v2[j]) {
            sol[++sol[0]] = v1[i];
            i--;
            j--;
        } else if(dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else j--;
    }

    for(int i = sol[0]; i >= 1; i--)
        printf("%d ", sol[i]);
    printf("\n");
    return 0;
}
