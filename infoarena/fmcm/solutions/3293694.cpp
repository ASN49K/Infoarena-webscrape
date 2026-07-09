#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("fmcm.in");
ofstream out("fmcm.out");

int const INF = 1e9+7;

struct Edge{
  short to;
  short flow;
  short cost; 
};

vector <Edge> edges;

int const NMAX = 350;
int dist[1 + NMAX];
short edge_ind[1 + NMAX];
vector <short> g[1 + NMAX];

bool isQueue[1 + NMAX];

void addEdge(short from, short to, short flow, short cost) {
  edges.push_back({to, flow, cost});
  edges.push_back({from, 0, -cost});
  g[from].push_back(edges.size()-2); 
  g[to].push_back(edges.size()-1);
}

void computeBellman(short source, short n) {
  for(short i = 1;i <= n;i++) {
    dist[i] = INF;
    isQueue[i] = false;
    edge_ind[i] = 0;
  }
  queue <short> q;
  dist[source] = 0;
  isQueue[source] = true;
  q.push(source);
  while(!q.empty()) { 
    short from = q.front();
    isQueue[from] = false;
    q.pop();
    for(int i = 0;i < g[from].size();i++) {
      short to = edges[g[from][i]].to, flow = edges[g[from][i]].flow, cost = edges[g[from][i]].cost;
      if(flow > 0 && dist[from] + cost < dist[to]) {
	dist[to] = dist[from] + cost;
	if(!isQueue[to]) {
          isQueue[to] = true;
	  q.push(to);
	}
      }
    }
  } 
}	

void pushFlow(short ind, short flow) {
  edges[ind].flow -= flow;
  edges[ind^1].flow += flow;
}

int computePushed(int node, int minflow, int sink) {
  if(node == sink) {
    return minflow;
  } else {
    int pushed = 0;
    for(int i = edge_ind[node];i < g[node].size();i++) {
      int to = edges[g[node][i]].to, flow = edges[g[node][i]].flow, cost = edges[g[node][i]].cost;
      if(flow > 0 && dist[to] != INF && dist[node] + cost <= dist[to]) {
	int tempPush = computePushed(to, min(minflow - pushed, flow), sink);
	pushFlow(g[node][i], tempPush);
	pushed += tempPush;
	if(pushed == minflow) {
          return pushed;
	}
      }
      edge_ind[node]++;
    }
    return pushed;
  }
}

int computeDinic(int source, int sink, int n) {
  int ans = 0;
  bool canPush = true;
  while(canPush) {
    computeBellman(source, n);
    int pushed = computePushed(source, INF, sink);
    ans += pushed;
    canPush = false;
    if(pushed > 0) {
      canPush = true;
    }
  }
  return ans;
}

int main() {
  
  int n, m, source, sink;
  in >> n >> m >> source >> sink;
  for(int i = 1;i <= m;i++) {
    int a, b, flow, cost;
    in >> a >> b >> flow >> cost;
    addEdge(a, b, flow, cost);
  }
  int maxflow = computeDinic(source, sink, n);
  int mincost = 0;
  for(int i = 0;i < edges.size();i+=2) {
    int used = edges[i^1].flow, cost = edges[i].cost;
    mincost += used * cost;
  }
  out << mincost << '\n';
  return 0;
}
