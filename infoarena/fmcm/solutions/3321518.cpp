#include <iostream>
#include <fstream>
#include <cassert>

#include <algorithm>
#include <vector>

#include <queue>

template<class T> using vec = std::vector<T>;

constexpr int INF = 1e9;
constexpr int NIL = -1;

struct Flux {
  struct Edge {
    int u, cap, cost, rev_idx;
    Edge( int u, int cap, int cost, int rev_idx ): u(u), cap(cap), cost(cost), rev_idx(rev_idx) {}
  };

  int n;
  vec<vec<Edge>> adj;

  vec<int> old_dist;

  vec<Edge*> prev, prev_rev;

  Flux( int n ): n(n), adj(n), old_dist(n), prev(n), prev_rev(n) {}
  
  void push_edge( int a, int b, int cap, int cost ) {
    adj[a].emplace_back( b, cap, cost, (int)adj[b].size() );
    adj[b].emplace_back( a, 0, -cost, (int)adj[a].size() - 1 );
  }

  void init_pot( int src ) {
    vec<int> dist(n, +INF);
    dist[src] = 0;

    std::queue<int> q;
    q.push( src );

    while( !q.empty() ){
      int u = q.front();
      q.pop();

      for( const Edge &e : adj[u] ){
        if( !e.cap ) continue;
        if( dist[u] + e.cost >= dist[e.u] ) continue;

        dist[e.u] = dist[u] + e.cost;
        q.push( e.u );
      }
    }

    old_dist = dist;
  }

  bool dijkstra( int src, int dest ) {
    vec<int> dist(n, +INF);
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
    
    return dist[dest] < +INF;
  }

  std::pair<int, int> push( int src, int dest ) {
    int flow = 0, cost = 0;
    init_pot( src );

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
};

int main() {
  std::ifstream fin("fmcm.in");
  std::ofstream fout("fmcm.out");

  int n, m, src, dest;
  fin >> n >> m >> src >> dest;
  src--; dest--;

  Flux mata(n);
  for( int i = 0; i < m; i++ ){
    int a, b, cap, cost;
    fin >> a >> b >> cap >> cost;
    mata.push_edge( --a, --b, cap, cost );
  }

  auto [_, ret] = mata.push( src, dest );

  fout << ret << '\n';
  return 0;
}
