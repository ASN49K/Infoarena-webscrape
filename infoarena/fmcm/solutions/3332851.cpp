#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

const int INF = 2e9;

int n, m, S, D;
vector<vector<int>> C, G, Cost;
vector<int> parent, dist;
vector<bool> inQueue;

bool spfa(int start, int end) {
    dist.assign(n + 1, INF);
    parent.assign(n + 1, 0);
    inQueue.assign(n + 1, false);
    
    queue<int> Q;
    Q.push(start);
    dist[start] = 0;
    inQueue[start] = true;

    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        inQueue[node] = false;

        for(int neighbor : G[node]) {
            if(C[node][neighbor] > 0 && dist[neighbor] > dist[node] + Cost[node][neighbor]) {
                dist[neighbor] = dist[node] + Cost[node][neighbor];
                parent[neighbor] = node;
                if(!inQueue[neighbor]) {
                    Q.push(neighbor);
                    inQueue[neighbor] = true;
                }
            }
        }
    }
    return dist[end] != INF;
}

int getMinCostMaxFlow(int start, int end) {
    int totalCost = 0;
    while (spfa(start, end)) {
        int pathFlow = INF;
        for (int v = end; v != start; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, C[u][v]);
        }
        for (int v = end; v != start; v = parent[v]) {
            int u = parent[v];
            C[u][v] -= pathFlow;
            C[v][u] += pathFlow;
        }
        totalCost += pathFlow * dist[end];
    }
    return totalCost;
}

int main() {
    fin >> n >> m >> S >> D;
    
    G.resize(n + 1);
    C.resize(n + 1, vector<int>(n + 1, 0));
    Cost.resize(n + 1, vector<int>(n + 1, 0));

    for (; m; --m) {
        int x, y, cap, cst;
        fin >> x >> y >> cap >> cst;
        G[x].push_back(y);
        G[y].push_back(x);
        C[x][y] = cap;
        Cost[x][y] = cst;
        Cost[y][x] = -cst;
    }
    fin.close();

    fout << getMinCostMaxFlow(S, D) << "\n";
    return 0;
}