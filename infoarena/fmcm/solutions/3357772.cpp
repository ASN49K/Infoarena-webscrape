#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream cin("maxflow.in");
ofstream cout("maxflow.out");

const int N = 1010;
const int INF = 1e9;

int n, m, s, t;
int capacity[N][N];
vector<int> adj[N];
int parent[N];
bool visited[N];

bool bfs() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = -1;
        visited[i] = false;
    }
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
                
                if (v == t) return true;
            }
        }
    }
    
    return false;
}

int main() {
    cin >> n >> m >> s >> t;
    
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += c;
    }
    
    long long max_flow = 0;
    
    while (bfs()) {
        int path_flow = INF;
        int cur = t;
        
        while (cur != s) {
            int prev = parent[cur];
            path_flow = min(path_flow, capacity[prev][cur]);
            cur = prev;
        }
        
        cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= path_flow;
            capacity[cur][prev] += path_flow;
            cur = prev;
        }
        
        max_flow += path_flow;
    }
    
    cout << max_flow;
    
    return 0;
}