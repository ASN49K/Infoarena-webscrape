#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 355;

struct Muchie {
    int catre, inversa;
    int capacitate, cost;
};

vector<Muchie> graf[MAXN];
int N, M, S, D;
int distanta[MAXN], real_d[MAXN], tata[MAXN], potential[MAXN];
bool vizitat[MAXN];


void adaugaMuchie(int de_la, int la, int capacitate, int cost) {
    graf[de_la].push_back({la, (int)graf[la].size(), capacitate, cost});
    graf[la].push_back({de_la, (int)graf[de_la].size() - 1, 0, -cost});
}


bool bellmanFord() {
    fill(potential, potential + N + 1, INF);
    potential[S] = 0;
    queue<int> Q;
    vector<bool> inCoada(N + 1, false);
    Q.push(S);
    inCoada[S] = true;

    while (!Q.empty()) {
        int nod = Q.front();
        Q.pop();
        inCoada[nod] = false;

        for (auto &e : graf[nod]) {
            if (e.capacitate > 0 && potential[nod] + e.cost < potential[e.catre]) {
                potential[e.catre] = potential[nod] + e.cost;
                if (!inCoada[e.catre]) {
                    Q.push(e.catre);
                    inCoada[e.catre] = true;
                }
            }
        }
    }

    return potential[D] != INF;
}


bool dijkstra() {
    fill(distanta, distanta + N + 1, INF);
    fill(vizitat, vizitat + N + 1, false);
    distanta[S] = 0;
    real_d[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [cst, nod] = pq.top(); pq.pop();
        if (vizitat[nod]) continue;
        vizitat[nod] = true;

        for (int i = 0; i < graf[nod].size(); ++i) {
            Muchie &e = graf[nod][i];
            if (e.capacitate > 0) {
                int costRedus = e.cost + potential[nod] - potential[e.catre];
                if (distanta[e.catre] > distanta[nod] + costRedus) {
                    distanta[e.catre] = distanta[nod] + costRedus;
                    real_d[e.catre] = real_d[nod] + e.cost;
                    tata[e.catre] = nod;
                    pq.push({distanta[e.catre], e.catre});
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i)
        if (distanta[i] < INF)
            potential[i] += distanta[i];

    return distanta[D] != INF;
}

pair<int, int> fluxMaximCostMinim() {
    int flux_total = 0, cost_total = 0;

    if (!bellmanFord()) return {0, 0};

    while (dijkstra()) {
        int flux = INF;
        for (int v = D; v != S; v = tata[v]) {
            int u = tata[v];
            for (auto &e : graf[u]) {
                if (e.catre == v && e.capacitate > 0) {
                    flux = min(flux, e.capacitate);
                    break;
                }
            }
        }

        for (int v = D; v != S; v = tata[v]) {
            int u = tata[v];
            for (int i = 0; i < graf[u].size(); ++i) {
                Muchie &e = graf[u][i];
                if (e.catre == v && e.capacitate > 0) {
                    e.capacitate -= flux;
                    graf[v][e.inversa].capacitate += flux;
                    break;
                }
            }
        }

        flux_total += flux;
        cost_total += flux * real_d[D];
    }

    return {flux_total, cost_total};
}


void citireDate() {
    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (int i = 0; i < M; ++i) {
        int x, y, cap, cost;
        scanf("%d %d %d %d", &x, &y, &cap, &cost);
        adaugaMuchie(x, y, cap, cost);
    }
}

int main() {
    freopen("fmcm.in", "r", stdin);
    freopen("fmcm.out", "w", stdout);

    citireDate();
    auto rezultat = fluxMaximCostMinim();
    printf("%d\n", rezultat.second);

    return 0;
}
