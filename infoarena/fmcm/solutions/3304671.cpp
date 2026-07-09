#include <bits/stdc++.h>

using namespace std;

#define ST_DIO 0
#if ST_DIO
    #define fin cin
    #define fout cout
#else
    ifstream fin("fmcm.in");
    ofstream fout("fmcm.out");
#endif  // ST_DIO

const int INF = 1e9 + 7;
struct Muchie {
    int x, y, c;
};
int n, m, i, j, st, sf, lim[352][352], flux[352][352], rasp;
int potent[352], cost[352], tata[352], costMuchii[352][352];
vector<Muchie> gr[352];
Muchie muchii[12502];

static inline bool Dijkastra() {
    for(int i = 1; i <= n; i++) tata[i] = -1;
    for(int i = 1; i <= n; i++) cost[i] = INF;
    multiset<pair<int, int>> s;


    cost[st] = 0;

    s.insert({0, st});

    while(!s.empty()) {
        int costCur = s.begin()->first;
        int  nodCur = s.begin()->second;
        s.erase(s.begin());

        //cout << costCur << " " << nodCur << "\n";

        if(cost[nodCur] < costCur) continue;

        for(Muchie urm : gr[nodCur]) {
            int costUrm = urm.c - potent[urm.y] + potent[nodCur] + cost[nodCur];
            if(costUrm < cost[urm.y] && lim[nodCur][urm.y] > flux[nodCur][urm.y]) {
                cost[urm.y] = costUrm;
                tata[urm.y] = nodCur;
                s.insert({cost[urm.y], urm.y});
            }
        }
    }
    //cout << "\n";

    if(cost[sf] == INF) return false;
    for(int i = 1; i <= n; i++) {
        potent[i] = cost[i] + potent[i] - potent[st];
    }
    return true;
}

static inline void BackTrack() {
    int cur = sf;
    int ma = INF;
    while(cur != st) {
        ma = min(ma, lim[tata[cur]][cur] - flux[tata[cur]][cur]);
        cur = tata[cur];
    }

    cur = sf;
    while(cur != st) {
        flux[tata[cur]][cur] += ma;
        flux[cur][tata[cur]] -= ma;
        rasp += ma * costMuchii[tata[cur]][cur];
        cur = tata[cur];
    }
}

int main() {
    if(ST_DIO) ios_base::sync_with_stdio(false);
    fin.tie(nullptr);
    fout.tie(nullptr);

    fin >> n >> m >> st >> sf;
    for(i = 1; i <= n; i++) potent[i] = INF;

    potent[st] = 0;
    for(i = 1; i <= m; i++) {
        int x, y, fma, cost;
        fin >> x >> y >> fma >> cost;
        muchii[i] = {x, y, cost};

        gr[x].push_back({x, y,  cost});
        gr[y].push_back({y, x, -cost});
        lim[x][y] += fma;

        costMuchii[x][y] =  cost;
        costMuchii[y][x] = -cost;
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            Muchie cur = muchii[j];
            if(potent[cur.x] != INF) potent[cur.y] = min(potent[cur.y], potent[cur.x] + cur.c);
        }
    }

    while(Dijkastra())
        BackTrack();

    fout << rasp;

    return 0;
}
