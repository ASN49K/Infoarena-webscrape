#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, rev;
    int cap, cost;
};

int N, M, S, D;
vector<vector<Edge>> graph;
vector<int> dist, potential, parent, parentEdge;
vector<bool> inQueue;

bool bellmanFord() {
    dist.assign(N + 1, INF);
    dist[S] = 0;
    inQueue.assign(N + 1, false);
    queue<int> q;
    q.push(S);
    inQueue[S] = true;
    vector<int> cnt(N + 1, 0);
    cnt[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inQueue[u] = false;
        for (const auto& e : graph[u]) {
            if (e.cap > 0 && dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                if (!inQueue[e.to]) {
                    q.push(e.to);
                    inQueue[e.to] = true;
                    cnt[e.to]++;
                    if (cnt[e.to] > N) return false;
                }
            }
        }
    }
    return true;
}

bool dijkstra() {
    dist.assign(N + 1, INF);
    dist[S] = 0;
    parent.assign(N + 1, -1);
    parentEdge.assign(N + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dist[u]) continue;
        for (int i = 0; i < (int)graph[u].size(); ++i) {
            const Edge& e = graph[u][i];
            if (e.cap > 0) {
                int newDist = dist[u] + e.cost + potential[u] - potential[e.to];
                if (newDist < dist[e.to]) {
                    dist[e.to] = newDist;
                    parent[e.to] = u;
                    parentEdge[e.to] = i;
                    pq.push({newDist, e.to});
                }
            }
        }
    }
    return dist[D] != INF;
}

int minCostMaxFlow(int& flow) {
    potential.assign(N + 1, 0);
    if (!bellmanFord()) return INF;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] < INF) potential[i] = dist[i];
    }
    int cost = 0;
    flow = 0;
    while (dijkstra()) {
        for (int i = 1; i <= N; ++i) {
            if (dist[i] < INF) potential[i] += dist[i];
        }
        int add = INF;
        for (int v = D; v != S; v = parent[v]) {
            int u = parent[v];
            int idx = parentEdge[v];
            add = min(add, graph[u][idx].cap);
        }
        flow += add;
        for (int v = D; v != S; v = parent[v]) {
            int u = parent[v];
            int idx = parentEdge[v];
            Edge& e = graph[u][idx];
            e.cap -= add;
            graph[e.to][e.rev].cap += add;
            cost += add * e.cost;
        }
    }
    return cost;
}

int main() {
    ifstream fin("fmcm.in");
    fin >> N >> M >> S >> D;
    graph.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int x, y, c, z;
        fin >> x >> y >> c >> z;
        graph[x].push_back({y, (int)graph[y].size(), c, z});
        graph[y].push_back({x, (int)graph[x].size() - 1, 0, -z});
    }
    fin.close();
    int flow;
    int minCost = minCostMaxFlow(flow);
    ofstream fout("fmcm.out");
    fout << minCost << "\n";
    fout.close();
    return 0;
}