#include <bits/stdc++.h>
const int INF = 1e9;
struct Flow{
  struct Edge{
    int u, cap, cost, rev_idx;
    Edge(int u, int cap, int cost, int rev_idx) : u(u), cap(cap), cost(cost), rev_idx(rev_idx){}
  };
  int n;
  std::vector<std::vector<Edge>> adj;
  std::vector<int> old_dist;

  std::vector<Edge*> prev;
  std::vector<Edge*> prev_rev;

  Flow(int n) : n(n), adj(n + 1), old_dist(n + 1), prev(n + 1), prev_rev(n + 1){};

  void add_edge(int u, int v, int cap, int cost) {
    adj[u].emplace_back(v, cap, cost, adj[v].size());
    adj[v].emplace_back(u, 0, -cost, adj[u].size() - 1);
  }

  void start_dist(int s) {
    std::queue<int> q;
    for( int i = 1; i <= n; i++ )
      old_dist[i] = INF;
    old_dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for( auto &e : adj[u] ) {
        if(e.cap != 0 && old_dist[e.u] > old_dist[u] + 1) {
          old_dist[e.u] = old_dist[u] + 1;
          q.push(e.u);
        }
      }
    }
  }
  bool dijkstra(int s, int t) {
    std::vector<int> dist(n + 1, INF);
    std::priority_queue<std::pair<int, int>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
      auto [cost, u] = pq.top();
      pq.pop();

      if(-cost != dist[u])
        continue;
      for( auto &e : adj[u] ) {
        if(e.cap == 0)
          continue;
        int x = dist[u] + old_dist[u] - old_dist[e.u] + e.cost;
        if( x < dist[e.u] ) {
          dist[e.u] = x;
          pq.push({-dist[e.u], e.u});
          prev[e.u] = &e;
          prev_rev[e.u] = &adj[e.u][e.rev_idx];
        }
      }
    }

    for( int i = 1; i <= n; i++ )
      old_dist[i] += dist[i];
    return dist[t] < INF;
  }
  std::pair<int, int> flowcost(int s, int t) {
    start_dist(s);
    int flow = 0, cost = 0;
    while(dijkstra(s, t)) {
      int new_flow = INF, new_cost = 0;
      for( int a = t; a != s; a = prev_rev[a]->u ) {
        new_flow = std::min(new_flow, prev[a]->cap);
        new_cost += prev[a]->cost;
      }
      flow += new_flow;
      cost += new_cost * new_flow;
      for( int a = t; a != s; a = prev_rev[a]->u ) {
        prev_rev[a]->cap += new_flow;
        prev[a]->cap -= new_flow;
      }
    }
    return {flow, cost};
  }
};

int main() {
  std::ifstream fin("fmcm.in");
  std::ofstream fout("fmcm.out");

  int n, m, src, dest;
  fin >> n >> m >> src >> dest;

  Flow flow(n);
  for( int i = 0; i < m; i++ ){
    int a, b, cap, cost;
    fin >> a >> b >> cap >> cost;
    flow.add_edge( a, b, cap, cost );
  }

  auto [_, ret] = flow.flowcost( src, dest );

  fout << ret << "\n";
  return 0;
}
