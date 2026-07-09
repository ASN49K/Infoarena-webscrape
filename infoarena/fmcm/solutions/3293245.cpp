#include <stdio.h>

#include <queue>
#include <vector>
#include <algorithm>

namespace Flow {
  const int MAXN = 350;
  constexpr int INF = 1e9;
  
  struct Edge {
    int u, cap, cost, rev_idx;
    Edge( int a, int b, int c, int d ): u(a), cap(b), cost(c), rev_idx(d) {}
  };

  int n;
  std::vector<Edge> adj[MAXN];
  int old_dist[MAXN];
  int dist[MAXN];

  Edge *prev[MAXN];
  Edge *prev_rev[MAXN];

  void init( int __n ) { n = __n; }
  void push_edge( int from, int to, int cap, int cost ) {
    adj[from].emplace_back( to, cap, +cost, (int)adj[to].size() );
    adj[to].emplace_back( from, 0, -cost, (int)adj[to].size() - 1 );
  }
  
  void init_pot( int src ) {
    for( int i = 0; i < n; i++ )
      dist[i] = +INF;

    std::queue<int> q({ src });
    dist[src] = 0;

    while( !q.empty() ){
      int u = q.front();
      q.pop();

      for( auto [v, cap, cost, __] : adj[u] )
        if( cap && dist[u] + cost < dist[v] ){
          dist[v] = dist[u] + cost;
          q.push( v );
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
      if( mdist != -dist[u] )
        continue;

      for( Edge &e : adj[u] ){
        if( !e.cap )
          continue;

        int aux = dist[u] + e.cost - (old_dist[e.u] - old_dist[u]);
        if( aux >= dist[e.u] )
          continue;

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

    int flow = 0, ret = 0;
    while( dijkstra( src, dest ) ){
      int augment_flow = +INF, augment_cost = 0;

      for( int u = dest; u != src; u = prev_rev[u]->u ){
        augment_flow = std::min( augment_flow, prev[u]->cap );
        augment_cost += prev[u]->cost;
      }

      flow += augment_flow;
      ret += augment_flow * augment_cost;

      for( int u = dest; u != src; u = prev_rev[u]->u ){
        prev[u]->cap -= augment_flow;
        prev_rev[u]->cap += augment_flow;
      }
    }

    return { flow, ret };
  }
}

int main() {
  FILE *fin = fopen( "fmcm.in", "r" );
  FILE *fout = fopen( "fmcm.out", "w" );

  int n, m, src, dest;
  fscanf( fin, "%d%d %d%d", &n, &m, &src, &dest );
  src--; dest--;

  Flow::init( n );

  for( int i = 0; i < m; i++ ){
    int from, to, cap, cost;
    fscanf( fin, "%d%d %d%d", &from, &to, &cap, &cost );
    Flow::push_edge( --from, --to, cap, cost );
  }

  auto [max_flow, min_cost] = Flow::push_flow( src, dest );
  fprintf( fout, "%d\n", min_cost );

  fclose( fin );
  fclose( fout );
  return 0;
}
