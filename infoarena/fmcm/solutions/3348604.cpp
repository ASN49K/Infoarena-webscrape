#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream in("fmcm.in");
ofstream out("fmcm.out");

int const INF = 1e9+7;

int const NMAX = 350;

struct Karp {

  struct Edge{
    int from;
    int to;
    int capacity;
    int cost;
  };

  vector <Edge> edges; 
  vector <int> g[1 + NMAX];
  int dist[1 + NMAX];
  int minflow[1 + NMAX];
  int acc[1 + NMAX]; 
  int prevEdge[1 + NMAX]; 
  bool isQueue[1 + NMAX];
  bool visit[1 + NMAX];

  int maxflow = 0, mincost = 0;

  void addEdge(int from, int to, int capacity, int cost) {
    edges.push_back({from, to, capacity, cost});
    g[from].push_back(edges.size()-1);
    edges.push_back({to, from, 0, -cost});
    g[to].push_back(edges.size()-1);
  }

  bool computeBellman(int source, int sink, int n) {
    for(int i = 1;i <= n;i++) {
      dist[i] = INF;
      isQueue[i] = false;
    }
    dist[source] = 0;
    queue <int> q;
    q.push(source);
    isQueue[source] = true;
    while(!q.empty()) {
      int from = q.front();
      isQueue[from] = false;
      q.pop();
      for(int i = 0;i < g[from].size();i++) {
        int edgeInd = g[from][i];
        int to = edges[edgeInd].to, capacity = edges[edgeInd].capacity, cost = edges[edgeInd].cost;
        if(capacity > 0 && dist[from] + cost < dist[to]) {
          dist[to] = dist[from] + cost;
          if(!isQueue[to]) {
            q.push(to);
            isQueue[to] = true;
          }
        }
      }
    }
    for(int i = 1;i <= n;i++) {
      acc[i] = dist[i];
    }
    if(dist[sink] == INF) {
      return false;
    }
    return true;
  }

  bool computeDijkstra(int source, int sink, int n) {
    for(int i = 1;i <= n;i++) {
      dist[i] = INF;
      visit[i] = false;
    }
    priority_queue <pair <int, int>> pq;
    dist[source] = 0;
    minflow[source] = INF;
    pq.push({0, source});
    while(!pq.empty()) {
      int from = pq.top().second;
      pq.pop();
      if(!visit[from]) {
        visit[from] = true;
        for(int i = 0;i < g[from].size();i++) {
          int edgeInd = g[from][i];
          int to = edges[edgeInd].to, capacity = edges[edgeInd].capacity, cost = edges[edgeInd].cost;
          cost += acc[from] - acc[to];
          if(capacity > 0 && dist[from] + cost < dist[to]) {
            dist[to] = dist[from] + cost; 
            minflow[to] = min(capacity, minflow[from]);
            pq.push({-dist[to], to});
            prevEdge[to] = edgeInd;  
          }
        }
      }
    }
    for(int i = 1;i <= n;i++) {
      acc[i] = dist[i] - (acc[source] - acc[i]);
    }
    if(dist[sink] == INF) {
      return false;
    }
    return true;
  }

  void computePushed(int source, int sink) {
    int node = sink, totalFlow = minflow[sink];
    while(node != source) {
      int edgeInd = prevEdge[node];  
      mincost += edges[edgeInd].cost * totalFlow;
      edges[edgeInd].capacity -= totalFlow;
      edges[edgeInd^1].capacity += totalFlow;
      node = edges[edgeInd].from;
    }
    maxflow += totalFlow;
  }

  void computeMinCostMaxFlow(int source, int sink, int n) {
    if(computeBellman(source, sink, n)) {
      while(computeDijkstra(source, sink, n)) {
        computePushed(source, sink);
      }
    }
  }

};

int main() {

  int n, m, source, sink;
  Karp karp;
  in >> n >> m >> source >> sink;
  for(int i = 1;i <= m;i++) {
    int a, b, capacity, cost;
    in >> a >> b >> capacity >> cost;
    karp.addEdge(a, b, capacity, cost);
  }
  karp.computeMinCostMaxFlow(source, sink, n);
  out << karp.mincost << '\n';
  return 0;
}
