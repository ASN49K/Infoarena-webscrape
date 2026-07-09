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

int A[5 + N], B[5 + N], sol[5 + N];
int dp[5 + N][5 + N];

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m, ans;

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &B[i]);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(A[i] == B[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
        }
    }

    ans = dp[n][m];
    printf("%d\n", ans);

    for(int i = n, j = m; i > 0 && j > 0; ) {
        if(A[i] == B[j]) {
            sol[ans--] = A[i];
            --i;
            --j;
        } else {
            if(dp[i - 1][j] >= dp[i][j - 1])
                --i;
            else --j;
        }
    }

    for(int i = 1; i <= dp[n][m]; i++)
        printf("%d ", sol[i]);

    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
