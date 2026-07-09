#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 350; // Număr maxim de noduri
const int INF = INT_MAX;

struct Edge {
    int to, capacity, cost, flow, reverse_index;
};

vector<Edge> graph[MAXN];
int N, M, S, D;
int dist[MAXN], parent[MAXN], parentEdge[MAXN];
bool inQueue[MAXN];

// Adaugă o muchie cu capacitate și cost
void addEdge(int u, int v, int capacity, int cost) {
    Edge forward = { v, capacity, cost, 0, (int)graph[v].size() };
    Edge backward = { u, 0, -cost, 0, (int)graph[u].size() };
    graph[u].push_back(forward);
    graph[v].push_back(backward);
}

// Implementare Bellman-Ford pentru a găsi drumul de cost minim
bool bellmanFord() {
    fill(dist, dist + N + 1, INF);
    memset(parent, -1, sizeof(parent));
    memset(parentEdge, -1, sizeof(parentEdge));
    dist[S] = 0;
    inQueue[S] = true;

    queue<int> q;
    q.push(S);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (size_t i = 0; i < graph[u].size(); i++) {
            Edge& e = graph[u][i];
            if (e.flow < e.capacity && dist[u] + e.cost < dist[e.to]) {
                dist[e.to] = dist[u] + e.cost;
                parent[e.to] = u;
                parentEdge[e.to] = i;

                if (!inQueue[e.to]) {
                    q.push(e.to);
                    inQueue[e.to] = true;
                }
            }
        }
    }

    return dist[D] != INF;
}

// Funcția principală pentru flux maxim cu cost minim
pair<int, int> minCostMaxFlow() {
    int maxFlow = 0, minCost = 0;

    while (bellmanFord()) {
        // Determinăm fluxul maxim ce poate fi trimis pe această cale
        int pathFlow = INF;
        for (int v = D; v != S; v = parent[v]) {
            int u = parent[v];
            int idx = parentEdge[v];
            pathFlow = min(pathFlow, graph[u][idx].capacity - graph[u][idx].flow);
        }

        // Actualizăm fluxurile și costurile
        for (int v = D; v != S; v = parent[v]) {
            int u = parent[v];
            int idx = parentEdge[v];
            graph[u][idx].flow += pathFlow;
            graph[v][graph[u][idx].reverse_index].flow -= pathFlow;
            minCost += pathFlow * graph[u][idx].cost;
        }

        maxFlow += pathFlow;
    }

    return { maxFlow, minCost };
}

int main() {
    ifstream inFile("fmcm.in");
    ofstream outFile("fmcm.out");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error: Unable to open input or output file." << endl;
        return 1;
    }

    inFile >> N >> M >> S >> D;

    for (int i = 0; i < M; i++) {
        int x, y, c, z;
        inFile >> x >> y >> c >> z;
        addEdge(x, y, c, z);
    }

    pair<int, int> result = minCostMaxFlow();
    outFile << result.second << endl;

    inFile.close();
    outFile.close();

    return 0;
}
