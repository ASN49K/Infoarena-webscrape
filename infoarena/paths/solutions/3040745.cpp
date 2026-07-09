#include <bits/stdc++.h>
#define int long long

using namespace std;

ifstream fin("paths.in");
ofstream fout("paths.out");

const int lgmax = 20;
struct lca
{
  int n = 0;
  vector<vector<pair<int, int>>> g;
  vector<vector<int>> rmq;
  vector<int> depth, tin, tout;
  int p = 0;
  void dfs(int node, int parent, int d)
  {
    rmq[node][0] = parent;
    for (int i = 1; i <= lgmax; ++i)
    {
      rmq[node][i] = rmq[rmq[node][i - 1]][i - 1];
    }
    depth[node] = d;
    tin[node] = ++p;
    for (auto i : g[node])
    {
      if (i.first != parent)
      {
        dfs(i.first, node, d + i.second);
      }
    }
    tout[node] = ++p;
  }
  void init(int _n, vector<vector<pair<int, int>>> _g)
  {
    n = _n;
    g = _g;
    rmq = vector<vector<int>>(n + 1, vector<int>(lgmax + 1));
    depth = tin = tout = vector<int>(n + 1);
    dfs(1, 1, 0);
  }
  bool isup(int a, int b)
  {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
  }
  int get_lca(int a, int b)
  {
    if (isup(a, b))
    {
      return a;
    }
    if (isup(b, a))
    {
      return b;
    }
    for (int i = lgmax; i >= 0; --i)
    {
      if (!isup(rmq[a][i], b))
      {
        a = rmq[a][i];
      }
    }
    return rmq[a][0];
  }
  int dist(int a, int b)
  {
    return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
  }
};

int n, k;

vector<vector<pair<int, int>>> g;

vector<int> ans;

vector<int> qui;

vector<int> coef;

lca lesgo;

int calc(int node, int parent)
{
  for (auto i : g[node])
  {
    if (i.first != parent)
    {
      return i.first;
    }
  }
  return node;
}

void dfs(int node, int parent, int cost)
{
   sort(g[node].begin(), g[node].end(), [&](pair<int, int> a, pair<int, int> b) {
    pair<int,int> dist1 = {lesgo.dist(a.first,node),a.first};
    pair<int,int> dist2 = {lesgo.dist(b.first,node),b.first};
    return dist1>dist2;
  });
  qui[node] = -1;
  for (auto i : g[node])
  {
    if (i.first != parent)
    {
      dfs(i.first, node, i.second);
    }
  }
  qui[node] = calc(node, parent);
  coef[qui[node]] += cost;
}

int calc()
{
  vector<int> aux = coef;
  sort(aux.begin() + 1, aux.end(), greater<int>());
  int ans = 0;
  for (int i = 1; i <= k; ++i)
  {
    ans += aux[i];
  }
  return ans;
}

void reroot(int node, int parent)
{
  ans[node] = calc();

  sort(g[node].begin(), g[node].end(), [&](pair<int, int> a, pair<int, int> b) {
    pair<int,int> dist1 = {lesgo.dist(a.first,node),a.first};
    pair<int,int> dist2 = {lesgo.dist(b.first,node),b.first};
    return dist1>dist2;
  });

  for (auto i : g[node])
  {
    if (i.first != parent)
    {
      int prev = qui[node];
      int prev2 = qui[i.first];

      coef[qui[i.first]] -= i.second;

      qui[node] = calc(node, i.first);

      coef[qui[node]] += i.second;

      reroot(i.first, node);

      coef[qui[node]] -= i.second;
      coef[prev2] += i.second;
      qui[node] = prev;
    }
  }
}

int32_t main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  fin >> n >> k;
  g = vector<vector<pair<int, int>>>(n + 1);

  coef = vector<int>(n + 1);
  qui = vector<int>(n + 1);
  ans = vector<int>(n + 1);

  for (int i = 1; i < n; ++i)
  {
    int a, b, c;
    fin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  lesgo.init(n, g);

  dfs(1, 0, 0);
  reroot(1, 0);

  for (int i = 1; i <= n; ++i)
  {
    fout << ans[i] << '\n';
  }
}