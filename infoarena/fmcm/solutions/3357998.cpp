#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int NMAX = 1005;
const int INF = 1e9;

struct Arc {
    int x, y, c, z;
};

int n, m, s, d;
vector<Arc> v;
vector<pair<int, int>> g[NMAX];
int dist[NMAX], tata[NMAX];
bool inCoada[NMAX];

void bf(int x) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    inCoada[x] = 1;
    while (!q.empty()) {
        int nod = q.front();
        q.pop();
        inCoada[nod] = 0;
        for (auto it : g[nod]) {
            int vec = it.first, cost = it.second;
            if (dist[vec] > dist[nod] + cost) {
                dist[vec] = dist[nod] + cost;
                tata[vec] = nod;
                if (!inCoada[vec]) {
                    q.push(vec);
                    inCoada[vec] = 1;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> d;
    for (int i = 1; i <= m; i++) {
        int x, y, c, z;
        cin >> x >> y >> c >> z;
        v.push_back({x, y, c, z});
        g[x].push_back({y, z});
        g[y].push_back({x, -z});
    }
    int sol = 0;
    while (1) {
        bf(s);
        if (dist[d] == INF) break;
        for (int i = 1; i <= n; i++) {
            for (auto& it : g[i]) {
                it.second += dist[i] - dist[it.first];
            }
        }
        int nr = INF;
        int nod = d;
        while (nod != s) {
            for (auto it : g[tata[nod]]) {
                if (it.first == nod) {
                    nr = min(nr, it.second);
                    break;
                }
            }
            nod = tata[nod];
        }
        sol += nr * dist[d];
        nod = d;
        while (nod != s) {
            for (auto& it : g[tata[nod]]) {
                if (it.first == nod) {
                    it.second -= nr;
                    break;
                }
            }
            for (auto& it : g[nod]) {
                if (it.first == tata[nod]) {
                    it.second += nr;
                    break;
                }
            }
            nod = tata[nod];
        }
    }
    cout << sol << '\n';
    return 0;
}