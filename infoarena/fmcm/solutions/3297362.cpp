#include <stdio.h>

#include <queue>
#include <vector>
#include <algorithm>

namespace Flow {
  const int MAXN = 1000;
  constexpr int INF = 1e9;
  
  struct Edge { int u, cap, cost, rev_idx; };
  std::vector<Edge> adj[MAXN];
  int dist[MAXN];
  int old_dist[MAXN];

  Edge *prev[MAXN];
  Edge *prev_rev[MAXN];

  int n;

  void init( int N ) { n = N; }
  void push_edge( int a, int b, int cap, int cost ) {
    adj[a].push_back({ b, cap, cost, (int)adj[b].size() });
    adj[b].push_back({ a, 0, -cost, (int)adj[a].size() - 1 });
  }

  void init_pot( int src ) {
    for( int i = 0; i < n; i++ )
      dist[i] = +INF;

    std::queue<int> q({ src });
    dist[src] = 0;
    while( !q.empty() ){
      int u = q.front();
      q.pop();

      for( Edge e : adj[u] )
        if( e.cap && dist[u] + e.cost < dist[e.u] ){
          dist[e.u] = dist[u] + e.cost;
          q.push( e.u );
        }
    }

    for( int i = 0; i < n; i++ )
      old_dist[i] = dist[i];
  }

  bool dijkstra( int src, int dest ) {
    for( int i = 0; i < n; i++ )
      dist[i] = +INF;

    std::priority_queue<std::pair<int, int>> pq;
    pq.emplace( -(dist[src] = 0), src );
    while( !pq.empty() ){
      auto [mdist, u] = pq.top();
      pq.pop();
      if( -dist[u] != mdist ) continue;

      for( Edge &e : adj[u] ){
        if( !e.cap ) continue;
        int aux = dist[u] + e.cost - old_dist[e.u] + old_dist[u];
        if( aux >= dist[e.u] ) continue;

        pq.emplace( -(dist[e.u] = aux), e.u );
        prev[e.u] = &e;
        prev_rev[e.u] = &adj[e.u][e.rev_idx];
      }
    }

    for( int i = 0; i < n; i++ )
      old_dist[i] += dist[i];

    return dist[dest] < +INF;
  }

  std::pair<int, int> push_flow( int src, int dest ) {
    init_pot( src );

    int flow = 0, cost = 0;
    while( dijkstra( src, dest ) ){
      int aug_flow = +INF, aug_cost = 0;
      for( int u = dest; u != src; u = prev_rev[u]->u ){
        aug_flow = std::min( aug_flow, prev[u]->cap );
        aug_cost += prev[u]->cost;
      }

      flow += aug_flow;
      cost += aug_flow * aug_cost;

      for( int u = dest; u != src; u = prev_rev[u]->u ){
        prev[u]->cap -= aug_flow;
        prev_rev[u]->cap += aug_flow;
      }
    }

    return { flow, cost };
  }
}

int main() {
  FILE *fin = fopen( "fmcm.in", "r" );
  FILE *fout = fopen( "fmcm.out", "w" );

  int n, m, src, dest;
  fscanf( fin, "%d%d%d%d", &n, &m, &src, &dest );
  src--; dest--;

  Flow::init( n );
  for( int i = 0; i < m; i++ ){
    int a, b, cap, cost;
    fscanf( fin, "%d%d%d%d", &a, &b, &cap, &cost );
    Flow::push_edge( --a, --b, cap, cost );
  }

  auto [flow, cost] = Flow::push_flow( src, dest );
  fprintf( fout, "%d\n", cost );

  fclose( fin );
  fclose( fout );
  return 0;
}
