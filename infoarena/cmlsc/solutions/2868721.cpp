#include <iostream>
#include <vector>

#define NMAX 1005
#define NNMAX 100005

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
          dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dimx, dimy, q, val[NMAX][NMAX],
    n, firstOcc[NNMAX], lg2[2 * NNMAX], niv[NNMAX],
    sparse[2 * NNMAX][20], etl;
char s[NMAX][NMAX];
bool v[NNMAX];
vector<int> adj[NNMAX], eulerTour;

void generLg2() {
    for(int i = 2; i < 2 * NNMAX; ++i)
        lg2[i] = lg2[i / 2] + 1;
}

inline bool inBounds(int x, int y) {
    return min(x, y) >= 1 && x <= dimx && y <= dimy;
}

inline void dfs(int x, int y) {
    val[x][y] = n;
    for(int i = 0; i < 8; ++i) {
        const int nx = x + dx[i], ny = y + dy[i];
        if(inBounds(nx, ny)) {
            if(s[nx][ny] == s[x][y] && !val[nx][ny]) {
                dfs(nx, ny);
            } else if(s[nx][ny] != s[x][y] && val[nx][ny]) {
                adj[val[nx][ny]].push_back(n);
                adj[n].push_back(val[nx][ny]);
            }
        }
    }
}

void generGraf() {
    for(int i = 1; i <= dimx; ++i)
        for(int j = 1; j <= dimy; ++j) {
            if(!val[i][j]) {
                n++;
                dfs(i, j);
            }
        }
}

inline void constructEulerTour(int nod = 1, int tata = 0) {
    v[nod] = 1;
    niv[nod] = niv[tata] + 1;
    firstOcc[nod] = eulerTour.size();
    eulerTour.push_back(nod);
    for(const auto &el : adj[nod]) {
        if(!v[el] && el != tata) {
            constructEulerTour(el, nod);
            eulerTour.push_back(nod);
        }
    }
}

void constructLCA() {
    for(int i = 1; i <= etl; ++i)
        sparse[i][0] = eulerTour[i];
    for(int sz = 1; (1 << sz) <= etl; ++sz) {
        for(int i = 1; i + (1 << sz) - 1 <= etl; ++i) {
            const int v1 = sparse[i][sz - 1],
                      v2 = sparse[i + (1 << (sz - 1))][sz - 1];
            if(niv[v1] < niv[v2]) sparse[i][sz] = v1;
            else sparse[i][sz] = v2;
        }
    }
}

inline int lca(int x, int y) {
    x = firstOcc[x];
    y = firstOcc[y];
    if(x > y) swap(x, y);
    const int lg2dist = lg2[y - x + 1],
              v1 = sparse[x][lg2dist],
              v2 = sparse[y - (1 << lg2dist) + 1][lg2dist];
    if(niv[v1] < niv[v2]) return v1;
    return v2;
}

int main()
{
    generLg2();
    freopen("pirati.in", "r", stdin);
    freopen("pirati.out", "w", stdout);
    scanf("%d%d%d", &dimx, &dimy, &q);
    for(int i = 1; i <= dimx; ++i)
        scanf("%s", s[i] + 1);
    generGraf();
    eulerTour.push_back(0);
    constructEulerTour();
    etl = eulerTour.size() - 1;
    constructLCA();
    for(int i = 1, x, y, z, w; i <= q; ++i) {
        scanf("%d%d%d%d", &x, &y, &z, &w);
        const int n1 = val[x][y], n2 = val[z][w], crt = lca(n1, n2);
        const int ans = niv[n1] + niv[n2] - 2 * niv[crt];
        printf("%d\n", ans / 2);
    }
    return 0;
}
