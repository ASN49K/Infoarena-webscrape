#include <bits/stdc++.h>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");
typedef int Matrice[352][352];
const int MAX = 1e9 + 7;
struct Muchie {
    int x, y, c;
};
int n, m, i, j, surs, dest, rasp;
int gol[352], cost[352], ant[352];
Matrice cap, costMch, flux;

vector<Muchie> gr[352];
Muchie mch[12502];

static inline bool Dijkstra(int surs, int dest) {
    for(int i = 1; i <= n; i++) {
        cost[i] = MAX;
        ant[i] = 0;
    }

    multiset<pair<int, int>> s;
    s.insert({0, surs});

    cost[surs] = 0;

    while(!s.empty()) {
        int nod = s.begin()->second;
        int cc = s.begin()->first;
        s.erase(s.begin());

        if(cc > cost[nod]) continue;

        for(Muchie urm : gr[nod]) {
            int costNou = urm.c - gol[urm.y] + gol[nod] + cost[nod];
            if(costNou < cost[urm.y] && cap[nod][urm.y] > flux[nod][urm.y]) {
                cost[urm.y] = costNou;
                ant[urm.y] = nod;
                s.insert({cost[urm.y], urm.y});
            }
        }
    }
    if(cost[dest] == MAX) return false;
    for(int i = 1; i <= n; i++) gol[i] += cost[i] - gol[dest];
    return true;
}

static inline void Reverse(int surs, int dest) {
    int poz = dest;
    int ma = MAX;
    while(poz != surs) {
        ma = min(ma, cap[ant[poz]][poz] - flux[ant[poz]][poz]);
        poz = ant[poz];
    }

    poz = dest;
    while(poz != surs) {
        flux[ant[poz]][poz] += ma;
        flux[poz][ant[poz]] -= ma;
        rasp += ma * costMch[ant[poz]][poz];
        poz = ant[poz];
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    fin.tie(nullptr);
    fout.tie(nullptr);

    fin >> n >> m >> surs >> dest;
    for(i = 1; i <= n; i++) gol[i] = MAX;

    gol[surs] = 0;
    for(i = 1; i <= m; i++) {
        int x, y, ma, cost;
        fin >> x >> y >> ma >> cost;
        mch[i] = {x, y, cost};

        gr[x].push_back({x, y,  cost});
        gr[y].push_back({y, x, -cost});
        cap[x][y] += ma;

        costMch[x][y] =  cost;
        costMch[y][x] = -cost;
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            Muchie cur = mch[j];
            if(gol[cur.x] != MAX) {
		gol[cur.y] = min(gol[cur.y], gol[cur.x] + cur.c);
	    }
        }
    }

    while(Dijkstra(surs, dest)) Reverse(surs, dest);

    fout << rasp;

    return 0;
}
