#include <stdio.h>

#include <vector>
#include <algorithm>
#include <queue>

using ll = long long;

struct Point {
  int x, y;
  Point( int x = 0, int y = 0 ): x(x), y(y) {}
};

int sdet( const Point &a, const Point &b, const Point &c ) {
  ll det = (a.x - b.x) * (ll)(a.y - c.y) - (a.y - b.y) * (ll)(a.x - c.x);
  if( det < 0 ) return -1;
  if( det > 0 ) return +1;
  return 0;
}

std::vector<Point> hull_half( const std::vector<Point> &points, int sgn ) {
  std::vector<Point> ret;

  for( Point P : points ){
    while( (int)ret.size() >= 2 && sdet( ret.end()[-2], ret.end()[-1], P ) * sgn < 0 )
      ret.pop_back();
    ret.push_back( P );
  }

  return ret;
}

std::vector<Point> hull( std::vector<Point> &points ){
  std::sort( points.begin(), points.end(), []( const Point &a, const Point &b ) -> bool {
    if( a.x != b.x )
      return a.x < b.x;
    return a.y < b.y;
  } );

  std::vector<Point> ret1 = hull_half( points, +1 );
  std::vector<Point> ret2 = hull_half( points, -1 );

  ret1.insert( ret1.end(), ret2.rbegin() + 1, ret2.rend() - 1 );
  return ret1;
}

namespace Flow {
  const int MAXN = 1000;
  const int INF = 1e9;
  
  struct Edge {
    int u, cap, cost, rev_idx;
    Edge( int u, int cap, int cost, int rev_idx ): u(u), cap(cap), cost(cost), rev_idx(rev_idx) {}
  };

  int n;
  std::vector<Edge> adj[MAXN];

  int dist[MAXN];
  int old_dist[MAXN];

  Edge *prev[MAXN];
  Edge *prev_rev[MAXN];

  void init( int N ) { n = N; }
  void push_edge( int from, int to, int cap, int cost ) {
    adj[from].emplace_back( to, cap, cost, (int)adj[to].size() );
    adj[to].emplace_back( from, 0, -cost, (int)adj[from].size() - 1 );
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
    pq.emplace( -0, src );
    dist[src] = 0;

    while( !pq.empty() ){
      auto top = pq.top();
      pq.pop();

      int u = top.second;
      if( dist[u] != -top.first )
        continue;

      for( Edge &e : adj[u] ){
        if( !e.cap )
          continue;

        int aux = dist[u] + e.cost - (old_dist[e.u] - old_dist[u]);
        if( aux < dist[e.u] ){
          dist[e.u] = aux;
          pq.emplace( -aux, e.u );

          prev_rev[e.u] = &adj[e.u][e.rev_idx];
          prev[e.u] = &e;
        }
      }
    }

    for( int i = 0; i < n; i++ )
      old_dist[i] += dist[i];

    return dist[dest] < +INF;
  }

  int min_cost_max_flow( int src, int dest ) {
    init_pot( src );

    int cost = 0;
    int flow = 0;

    while( dijkstra( src, dest ) ){
      int augment_flow = +INF, augment_cost = 0;
      for( int u = dest; u != src; u = prev_rev[u]->u ){
        augment_flow = std::min( augment_flow, prev[u]->cap );
        augment_cost += prev[u]->cost;
      }

      flow += augment_flow;
      cost += augment_flow * augment_cost;

      for( int u = dest; u != src; u = prev_rev[u]->u ){
        prev[u]->cap -= augment_flow;
        prev_rev[u]->cap += augment_flow;
      }
    }

    return cost;
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
    int from, to, cap, cost;
    fscanf( fin, "%d%d%d%d", &from, &to, &cap, &cost );
    Flow::push_edge( --from, --to, cap, cost );
  }

  fprintf( fout, "%d\n", Flow::min_cost_max_flow( src, dest ) );

  fclose( fin );
  fclose( fout );
  return 0;
}
