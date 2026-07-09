#include <fstream>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;
const int NMAX = 350;
using ll = long long;
const int INF = 1e8;

ifstream cin("fmcm.in");
ofstream cout("fmcm.out");

struct muchie {
    int nod;
    int flux;
    int cap;
    int cost;
    int pereche;
};
vector <vector <muchie>> v;

void addedge(int a, int b, int cap, int cost) {
    v[a].push_back({b, 0, cap, cost, -1});
    v[b].push_back({a, 0, 0, -cost, -1});
    v[a].back().pereche = v[b].size() - 1;
    v[b].back().pereche = v[a].size() - 1;
}

pair <int, int> tata[NMAX + 2];
int n, sursa, dest;

bitset <NMAX + 2> incoada;
int dist[NMAX + 2];
bool bellmanFord() {
    incoada = 0;
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        tata[i].first = 0;
        tata[i].second = -1;
        dist[i] = INF;
    }
    queue <int> q;
    incoada[sursa] = 1;
    dist[sursa] = 0;
    q.push(sursa);
    while(!q.empty()) {
        int now = q.front();
        incoada[now] = 0;
        q.pop();
        for(int i = 0; i < v[now].size(); i++) {
            muchie x = v[now][i];
            if(x.flux < x.cap && dist[x.nod] > dist[now] + x.cost) {
                dist[x.nod] = dist[now] + x.cost;
                tata[x.nod].first = now;
                tata[x.nod].second = i;
                if(!incoada[x.nod]) {
                    incoada[x.nod] = 1;
                    q.push(x.nod);
                }
            }
        }
    }
    return (dist[dest] < INF);
}

int recons(int nod, int minn) {
    while(tata[nod].first) {
        minn = min(minn, v[tata[nod].first][tata[nod].second].cap - v[tata[nod].first][tata[nod].second].flux);
        nod = tata[nod].first;
        if(minn <= 0)
            return minn;
    }
    return minn;
}

void change(int a, int b, int id, int val) { ///id = pozitia din v[a]
        v[a][id].flux += val;
        v[b][v[a][id].pereche].flux -= val;
}

void update(int nod, int add) {
    while(tata[nod].first) {
        change(tata[nod].first, nod, tata[nod].second, add);
        nod = tata[nod].first;
    }
}

int main() {
    int m;
    cin >> n >> m >> sursa >> dest;
    v.resize(n + 1);
    for(int i = 1; i <= m; i++) {
        int a, b, cap, cost;
        cin >> a >> b >> cap >> cost;
        addedge(a, b, cap, cost);
    }
    /*for(int i = 1; i <= n; i++) {
        cout << "Nodul " << i << '\n';
        for(auto x : v[i]) {
            cout << x.nod << " " << x.cap << " " << x.cost << '\n';
        }
    }*/
    while(bellmanFord()) {
        int add = recons(dest, INF); ///mergem DOAR pe drumul din bellman ford
        if(add > 0)
            update(dest, add);
        else
            break;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(auto x : v[i]) {
            if(x.cap > 0)
                ans += 1LL * x.flux * x.cost;
        }
    }
    cout << ans;
    return 0;
}