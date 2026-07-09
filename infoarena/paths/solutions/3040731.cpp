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
  int ans = -1;
  bool ok = false;
  for (auto i : g[node])
  {
    if (i.first != parent)
    {
      ok = true;
      if (ans == -1)
      {
        ans = qui[i.first];
      }
      else
      {
        if (lesgo.dist(qui[i.first], node) > lesgo.dist(ans, node))
        {
          ans = qui[i.first];
        }
        else
        {
          if (lesgo.dist(qui[i.first], node) == lesgo.dist(ans, node))
          {
            ans = min(ans, qui[i.first]);
          }
        }
      }
    }
  }
  if (!ok)
  {
    ans = node;
  }
  return ans;
}

void dfs(int node, int parent, int cost)
{
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
      qui[i.first] = prev2;
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