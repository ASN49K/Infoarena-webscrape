#include <stdio.h>

#include <algorithm>
#include <vector>
#include <queue>

const int MAXN = 1000;
const int INF = 1e9;

namespace Flow {
  struct Edge {
    int u, cap, cost, rev_idx;
    Edge( int u, int cap, int cost, int rev_idx ): u(u), cap(cap), cost(cost), rev_idx(rev_idx) {}
  };

  std::vector<Edge> adj[MAXN];
  int old_dist[MAXN];
  int dist[MAXN];
  int n;

  Edge *prev[MAXN];
  Edge *prev_rev[MAXN];

  void init( int N ) {
    n = N;
    for( int i = 0; i < n; i++ )
      adj[i].clear();
  }

  void push_edge( int from, int to, int cap, int cost ) {
    adj[from].emplace_back( to, cap, cost, (int)adj[to].size() );
    adj[to].emplace_back( from, 0, -cost, (int)adj[from].size() - 1 );
  }

  void init_dist( int src ) {
    for( int i = 0; i < n; i++ )
      dist[i] = +INF;
    
    std::queue<int> q({ src });
    dist[src] = 0;
    while( !q.empty() ){
      int u = q.front();
      q.pop();

      for( Edge e : adj[u] ){
        if( e.cap && dist[u] + e.cost < dist[e.u] ){
          dist[e.u] = dist[u] + e.cost;
          q.push( e.u );
        }
      }
    }

    for( int i = 0; i < n; i++ )
      old_dist[i] = dist[i];
  }

  bool dijkstra( int src, int dest ) {
    for( int i = 0; i < n; i++ )
      dist[i] = +INF;

    std::priority_queue<std::pair<int, int>> pq;
    pq.emplace( -0, src );
    dist[src] = 0;
    while( !pq.empty() ){
      auto top = pq.top();
      int u = top.second;
      pq.pop();

      if( dist[u] != -top.first )
        continue;

      for( Edge &e : adj[u] ){
        if( !e.cap )
          continue;

        int aux = e.cost - (old_dist[e.u] - old_dist[u]);
        if( aux < dist[e.u] ){
          dist[e.u] = aux;
          prev[e.u] = &e;
          prev_rev[e.u] = &adj[e.u][e.rev_idx];
          pq.emplace( -aux, e.u );
        }
      }
    }

    for( int i = 0; i < n; i++ )
      old_dist[i] += dist[i];

    return dist[dest] < +INF;
  }

  int min_cost( int src, int dest ) {
    int ret = 0;

    while( dijkstra( src, dest ) ){
      int augment_flow = +INF, augment_cost = 0;
      for( int u = dest; u != src; u = prev_rev[u]->u ){
        augment_flow = std::min( augment_flow, prev[u]->cap );
        augment_cost += prev[u]->cost;
      }

      ret += augment_flow * augment_cost;

      for( int u = dest; u != src; u = prev_rev[u]->u ){
        prev[u]->cap -= augment_flow;
        prev_rev[u]->cap += augment_flow;
      }
    }

    return ret;
  }
}

int main() {
  FILE *fin = fopen( "fmcm.in", "r" );
  FILE *fout = fopen( "fmcm.out", "w" );

  int n, m, src, dest;
  fscanf( fin, "%d%d%d%d", &n, &m, &src, &dest );
  src--;
  dest--;

  Flow::init( n );

  for( int i = 0; i < m; i++ ){
    int a, b, cap, cost;
    fscanf( fin, "%d%d%d%d", &a, &b, &cap, &cost );
    a--;
    b--;

    Flow::push_edge( a, b, cap, cost );
  }

  fprintf( fout, "%d\n", Flow::min_cost( src, dest ) );

  fclose( fin );
  fclose( fout );
  return 0;
}
