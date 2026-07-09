#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define N_MAX 1024
vector<int> pos[N_MAX];

int a[N_MAX], b[N_MAX];
int v[N_MAX], nv;
int pre[N_MAX][N_MAX];
int n, m;

void update(int x) {
    if (nv == 0) {
        v[nv++] = x;
        return;
    }
    int* p = lower_bound(v, v + nv, x);
    int i = p - v;
    if (i == nv) {
        v[nv++] = x;
    } else {
        v[i] = x;
    }
    if (!pre[i][x]) {
        pre[i][x] = v[i-1];
    }
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        b[i] = x;
        pos[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        for (vector<int>::reverse_iterator it = pos[a[i]].rbegin(); it != pos[a[i]].rend(); it++) {
            update(*it);
        }
    }

    printf("%d\n", nv);
    vector<int> sol;
    if (nv > 0) {
        int x = v[nv - 1];
        int lung = nv - 1;
        while (lung >= 0 && (int)sol.size() < nv) {
            sol.push_back(x);
            x = pre[lung][x];
            lung--;
        }
    }
    reverse(sol.begin(), sol.end());

    for (vector<int>::iterator it = sol.begin(); it != sol.end(); it++) {
        printf("%d ", b[*it]);
    }
    printf("\n");
    /*int p = 0;
    for (int i = 1; i <= n; i++) {
        if (p >= (int)sol.size()) {
            break;
        }
        if (a[i] == b[sol[p]]) {
            p++;
        }
    }
    printf("%d\n", p);*/
    return 0;
}
