// #include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cassert>

#define ll long long

using namespace std;

ifstream cin("fmcm.in");
ofstream cout("fmcm.out");

const int NMAX = 350;
const int INF = 2e9;
const int MMAX = 12500 * 2;

struct PQElement {
    int node;
    int cost;
    bool operator < (const PQElement &other) const {
        return other.cost < cost;
    }
};

struct Edge {
    int a, b, capacity, cost;
}edges[MMAX + 1];

int n, m, source, dest;
vector<pair<int, int>> g[NMAX + 1];
int bf_cost[NMAX + 1];
bool in_q[NMAX + 1];
int cost[NMAX + 1];
pair<int, int> parent[NMAX + 1];

void add_edge(int a, int b, int c, int cost, int i) {
    g[a].push_back({b, i});
    g[b].push_back({a, i + m});
    edges[i] = {a, b, c, cost};
    edges[i + m] = {a, b, 0, -cost};
}

// bool dijkstra() {
//     for(int i = source; i <= dest; i++) {
//         cost[i] = INF;
//         parent[i] = 0;
//     }
//     cost[source] = 0;

//     priority_queue<PQElement> pq;
//     pq.push({source, 0});
//     while(!pq.empty()) {
//         auto [node, curent_cost] = pq.top();
//         pq.pop();

//         if(cost[node] != curent_cost) {
//             continue;
//         }

//         for(auto [next_node, edge_cost] : g[node]) {
//             int next_cost = curent_cost + edge_cost + bf_cost[node] - bf_cost[next_node];
//             if(flow[node][next_node] < capacity[node][next_node] && next_cost < cost[next_node]) {
//                 cost[next_node] = next_cost;
//                 parent[next_node] = node;
//                 pq.push({next_node, next_cost});
//             }
//         }
//     }
//     return parent[dest] != 0;
// }

bool bellman_ford() {
    for(int i = 1; i <= n; i++) {
        cost[i] = INF;
        parent[i] = {0, 0};
    }
    cost[source] = 0;
    queue<int> q;
    q.push(source);
    in_q[source] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        in_q[node] = 0;

        for(auto [next_node, edge_id] : g[node]) {
            int next_cost = cost[node] + edges[edge_id].cost;
            if(edges[edge_id].capacity > 0 && next_cost < cost[next_node]) {
                cost[next_node] = next_cost;
                parent[next_node] = {node, edge_id};
                if(!in_q[next_node]) {
                    in_q[next_node] = 1;
                    q.push(next_node);
                }
            }
        }
    }
    return parent[dest].first != 0;
}

void min_cost_max_flow() {
    ll min_cost = 0;
    while(bellman_ford()) {
        int min_flow = INF;
        for(int node = dest; node != source; node = parent[node].first) {
            min_flow = min(min_flow, edges[parent[node].second].capacity);
        }

        min_cost += (ll) min_flow * cost[dest];
        for(int node = dest; node != source; node = parent[node].first) {
            edges[parent[node].second].capacity -= min_flow;
            edges[parent[node].second + (parent[node].second <= m ? m : -m)].capacity += min_flow;
        }
    }
    cout << min_cost << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> source >> dest;
    for(int i = 1; i <= m; i++) {
        int a, b, c, cost;
        cin >> a >> b >> c >> cost;
        add_edge(a, b, c, cost, i);
    }
    min_cost_max_flow();

    return 0;
}