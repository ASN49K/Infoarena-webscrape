#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

const int maxn = 360, inf = 0x3f3f3f3f;

int n, m, s, d;
int cap[maxn][maxn], cst[maxn][maxn];
vector<int> v[maxn];
queue<int> q;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int originalDistance[maxn], dist[maxn], realDistance[maxn], p[maxn];
bool inQ[maxn];
int finalCost, finalFlow;

void bellmanford() {
    memset(originalDistance, inf, sizeof(originalDistance));
    originalDistance[s] = 0;
    q.push(s);
    inQ[s] = true;
    while(!q.empty()) {
        int x = q.front();
        inQ[x] = false;
        for(auto u : v[x]) {
            if(cap[x][u]) {
                if(originalDistance[x] + cst[x][u] < originalDistance[u]) {
                    originalDistance[u] = originalDistance[x] + cst[x][u];
                    if(inQ[u] == false) {
                        inQ[u] = true;
                        q.push(u);
                    }
                }
            }
        }

        q.pop();
    }
}

bool dijkstra() {
    memset(dist, inf, sizeof(dist));
    dist[s] = 0; realDistance[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty()) {
        int currCost = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        if(dist[currNode] != currCost) // eu pun acelasi nod de mai multe ori in pq daca e nevoie
            continue; // dar il iau doar atunci cand distanta e cea mai mica
        for(auto u : v[currNode]) {
            if(cap[currNode][u]) {
                int newDist = dist[currNode] + cst[currNode][u] + originalDistance[currNode] - originalDistance[u];
                if(newDist < dist[u]) {
                    dist[u] = newDist;
                    realDistance[u] = realDistance[currNode] + cst[currNode][u];
                    p[u] = currNode;
                    pq.push({dist[u], u});
                }
            }
        }
    }

    memcpy(originalDistance, realDistance, sizeof(originalDistance));
    if(dist[d] == inf) // daca nu a facut drum pana la destinatie, nu s-a mai imbunatatit,
        return false; // deci ne oprim

    int minim = inf, curCst = 0;
    for(int i = d; i != s; i = p[i]) {
        minim = min(minim, cap[p[i]][i]);
        curCst += cst[p[i]][i];
    }
    finalFlow += minim;
    finalCost += curCst * minim; // sau minim * realDistance[d]
    for(int i = d; i != s; i = p[i]) {
        cap[p[i]][i] -= minim;
        cap[i][p[i]] += minim;
    }
    return true;
}

int main()
{
    fin >> n >> m >> s >> d;
    int x, y;

    while(m --) {
        fin >> x >> y;
        fin >> cap[x][y] >> cst[x][y];
        cst[y][x] = -cst[x][y];
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bellmanford();
    while(dijkstra());

    fout << finalCost << '\n';

    fin.close();
    fout.close();
    return 0;
}