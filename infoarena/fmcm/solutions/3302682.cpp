#include <fstream>
#include <vector>
#include <queue>
#include <cassert>
//#include <priority_queue>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

const int NMAX = 350;
const int INF = 1e9;

struct PQElement {
    int node, cost;
    bool operator < (const PQElement &other) const {
        return other.cost < cost;
    }
};

int n, m, source, dest, min_cost;
int capacity[NMAX + 1][NMAX + 1];
int flow[NMAX + 1][NMAX + 1];
vector<pair<int, int>> g[NMAX + 1];

int bf_cost[NMAX + 1];
bool in_q[NMAX + 1];

int cost[NMAX + 1];
int parent[NMAX + 1];

bool dijkstra() {
    for(int i = 1; i <= n; i++) {
        cost[i] = INF;
        parent[i] = 0;
    }
    cost[source] = 0;

    priority_queue<PQElement> pq;
    pq.push({source, 0});
    while(!pq.empty()) {
        auto [node, curent_cost] = pq.top();
        pq.pop();

        if(cost[node] != curent_cost) {
            continue;
        }

        for(auto [next_node, edge_cost] : g[node]) {
            int next_cost = curent_cost + edge_cost + bf_cost[node] - bf_cost[next_node];
            if(flow[node][next_node] < capacity[node][next_node] && next_cost < cost[next_node]) {
                cost[next_node] = next_cost;
                parent[next_node] = node;
                pq.push({next_node, next_cost});
            }
        }
    }
    return parent[dest] != 0;
}

void bellman_ford() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        q.push(i);
        in_q[i] = 1;
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        in_q[node] = 0;

        for(auto [next_node, cost] : g[node]) {
            int next_cost = bf_cost[node] + cost;
            if(capacity[node][next_node] && next_cost < bf_cost[next_node]) {
                bf_cost[next_node] = next_cost;
                if(!in_q[next_node]) {
                    in_q[next_node] = 1;
                    q.push(next_node);
                }
            }
        }
    }
}

int main() {
    fin >> n >> m >> source >> dest;
    for(int i = 1; i <= m; i++) {
        int a, b, c, cost;
        fin >> a >> b >> c >> cost;

        g[a].push_back({b, cost});
        g[b].push_back({a, -cost});
        capacity[a][b] += c;
    }

    bellman_ford();
//    int iter = 2;
    while(dijkstra()) {
        int min_flow = INF;
        for(int node = dest; node != source; node = parent[node]) {
            min_flow = min(min_flow, capacity[parent[node]][node] - flow[parent[node]][node]);
        }

        min_cost += min_flow * (cost[dest] - bf_cost[source] + bf_cost[dest]);
        for(int node = dest; node != source; node = parent[node]) {
            flow[parent[node]][node] += min_flow;
            flow[node][parent[node]] -= min_flow;
        }

        for(int i = 1; i <= n; i++) {
            if(cost[i] < INF) {
                bf_cost[i] += cost[i];
            }
        }
    }
    fout << min_cost << '\n';

    return 0;
}
