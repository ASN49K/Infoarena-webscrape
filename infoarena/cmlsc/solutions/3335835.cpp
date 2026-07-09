#include <bits/stdc++.h>
using namespace std;

int m, n, a[1025], b[1025], sol[1025][1025];
pair<int, int> saritura[1025][1025];

void calc(int start_a, int start_b) {
    if(sol[start_a][start_b] > -1)
        return;
    if(start_a >= m || start_b >= n) {
        sol[start_a][start_b] = 0;
        saritura[start_a][start_b] = {-1, -1};
        return;
    }

    int rez_optim = 0;
    pair<int, int> sar_optim = {0, 0};
    if(a[start_a] == b[start_b]) {
        calc(start_a + 1, start_b + 1);
        if(sol[start_a + 1][start_b + 1] + 1 > rez_optim) {
            rez_optim = sol[start_a + 1][start_b + 1] + 1;
            sar_optim = {start_a, start_b};
        }
    }

    calc(start_a + 1, start_b);
    if(sol[start_a + 1][start_b] > rez_optim) {
        rez_optim = sol[start_a + 1][start_b];
        sar_optim = saritura[start_a + 1][start_b];
    }

    calc(start_a, start_b + 1);
    if(sol[start_a][start_b + 1] > rez_optim) {
        rez_optim = sol[start_a][start_b + 1];
        sar_optim = saritura[start_a][start_b + 1];
    }

    sol[start_a][start_b] = rez_optim;
    saritura[start_a][start_b] = sar_optim;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef LOCAL
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
#endif

    cin >> m >> n;
    for(int i = 0; i < m; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    for(int i = 0; i < 1025; ++i) {
        for(int j = 0; j < 1025; ++j) {
            sol[i][j] = -1;
        }
    }

    calc(0, 0);

    cout << sol[0][0] << '\n';

    int i = 0, j = 0;
    while(i < m && j < n) {
        if(a[i] == b[j]) {
            cout << a[i] << ' ';
            i++;
            j++;
        } else if(sol[i + 1][j] >= sol[i][j + 1]) {
            i++;
        } else {
            j++;
        }
    }


    return 0;
}