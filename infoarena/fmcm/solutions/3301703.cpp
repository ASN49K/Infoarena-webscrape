#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

template<typename T>
bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T>
bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }

using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9+5;

struct FlowGraph {
   struct Edge {
      int y, cap, cost, rev;
   };

   const int S = 0, D = 1;

   vector<int> dist;
   vector<bool> inq;
   vector<pii> prev;
   vector<vector<Edge>> g;

   FlowGraph() {
      add_node();
      add_node();
   }

   int add_node() {
      dist.push_back(0);
      inq.push_back(false);
      prev.push_back({});
      g.emplace_back();
      return sz(g) - 1;
   }

   void add_edge(int x, int y, int cap, int cost) {
      g[x].push_back({ y, cap, cost, sz(g[y]) });
      g[y].push_back({ x, 0, -cost, sz(g[x]) - 1 });
   }

   bool bellman() {
      fill(all(dist), INF);
      fill(all(inq), false);

      queue<int> q;
      q.push(S);
      inq[S] = true;
      dist[S] = 0;

      while (!q.empty()) {
         int x = q.front();
         q.pop();
         inq[x] = false;

         int i = 0;
         for (auto &[ y, cap, cost, _ ] : g[x]) {
            if (cap && ckmin(dist[y], dist[x] + cost)) {
               if (!inq[y]) {
                  inq[y] = true;
                  q.push(y);
               }
               prev[y] = { x, i };
            }
            i++;
         }
      }

      return dist[D] != INF;
   }

   pii compute() {
      int max_flow = 0, min_cost = 0;

      while (bellman()) {
         int flow = INF, x = D;
         
         while (x != S) {
            auto [ y, i ] = prev[x];
            flow = min(flow, g[y][i].cap);
            x = y;
         }

         x = D;
         while (x != S) {
            auto [ y, i ] = prev[x];
            g[y][i].cap -= flow;
            g[x][g[y][i].rev].cap += flow;
            x = y;
         }

         max_flow += flow;
         min_cost += flow * dist[D];
      }

      return { max_flow, min_cost };
   }
};

const int NMAX = 355;

int a[NMAX];

signed main() {
#ifdef LOCAL
   freopen("input.txt", "r", stdin);
#else
   freopen("fmcm.in", "r", stdin);
   freopen("fmcm.out", "w", stdout);
#endif

   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n, m, S, D;
   FlowGraph f;

   cin >> n >> m >> S >> D;

   for (int i = 1; i <= n; i++) {
      if (i != S && i != D) {
         a[i] = f.add_node();
      }
   }

   a[S] = f.S;
   a[D] = f.D;

   for (int i = 1, x, y, c, w; i <= m; i++) {
      cin >> x >> y >> c >> w;
      f.add_edge(a[x], a[y], c, w);
   }

   cout << f.compute().se << endl;
   
   return 0;
}
