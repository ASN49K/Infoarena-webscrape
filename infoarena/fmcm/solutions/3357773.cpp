#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

const int INF = INT_MAX;
const int NMAX = 355;

vector<pair<int, int>> adj[NMAX];
int capacity[NMAX][NMAX];
int cost[NMAX][NMAX];
int dist[NMAX];
int parent[NMAX];
bool inQueue[NMAX];

int n, m, source, sink;

bool bellmanFord() {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
        inQueue[i] = false;
    }
    queue<int> q;
    dist[source] = 0;
    q.push(source);
    inQueue[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int c = cost[u][v];
            if (capacity[u][v] > 0 && dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                parent[v] = u;
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }

    return dist[sink] != INF;
}

int main() {
    fin >> n >> m >> source >> sink;

    for (int i = 0; i < m; ++i) {
        int x, y, cap, c;
        fin >> x >> y >> cap >> c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, -c});
        capacity[x][y] = cap;
        cost[x][y] = c;
        cost[y][x] = -c;
    }

    int totalCost = 0;

    while (bellmanFord()) {
        int flow = INF;
        int cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            flow = min(flow, capacity[prev][cur]);
            cur = prev;
        }

        cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= flow;
            capacity[cur][prev] += flow;
            totalCost += flow * cost[prev][cur];
            cur = prev;
        }
    }

    fout << totalCost << '\n';
    return 0;
}