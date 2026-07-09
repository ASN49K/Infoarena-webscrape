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

struct final_boss
{
  int sum = 0;
  multiset<int, greater<int>> luate;
  multiset<int, greater<int>> neluate;
  void fill()
  {
    while (!neluate.empty() && (int)luate.size() < k)
    {
      sum += *neluate.begin();
      luate.insert(*neluate.begin());
      neluate.erase(neluate.begin());
    }
    // assert(luate.size() == k);
  }
  void add(int x)
  {

    if ((int)luate.size() > 0)
    {
      if (*prev(luate.end()) < x)
      {
        int val = *prev(luate.end());
        luate.erase(luate.find(val));
        neluate.insert(val);
        luate.insert(x);
        sum -= val;
        sum += x;
      }
      else
      {
        neluate.insert(x);
      }
    }
    else
    {
      neluate.insert(x);
    }

    fill();
  }
  void rem(int x)
  {
    if (luate.count(x))
    {
      sum -= x;
      luate.erase(luate.find(x));
    }
    else
    {
      neluate.erase(neluate.find(x));
    }
  }
};

vector<vector<pair<int, int>>> g;

vector<int> ans;

vector<int> qui;

vector<int> coef;

lca lesgo;

final_boss moisil;

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
            ans = max(ans, qui[i.first]);
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

void modif(int pos, int val)
{
  moisil.rem(coef[pos]);
  coef[pos] += val;
  moisil.add(coef[pos]);
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
  modif(qui[node], cost);
}

void reroot(int node, int parent)
{
  ans[node] = moisil.sum;

  set<pair<int, int>, greater<pair<int, int>>> lavoir;

  for (auto i : g[node])
  {
    lavoir.insert({lesgo.dist(qui[i.first], node), qui[i.first]});
  }

  for (auto i : g[node])
  {
    if (i.first != parent)
    {
      int prev = qui[node];
      int prev2 = qui[i.first];

      modif(qui[i.first], -i.second);
      lavoir.erase({lesgo.dist(qui[i.first], node), qui[i.first]});

      if (lavoir.empty())
      {
        qui[node] = node;
      }
      else
      {
        qui[node] = (*lavoir.begin()).second;
      }

      modif(qui[node], i.second);

      reroot(i.first, node);

      modif(qui[node], -i.second);
      modif(prev2, i.second);
      qui[node] = prev;
      lavoir.insert({lesgo.dist(prev2, node), prev2});
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

  for (int i = 1; i <= n; ++i)
  {
    moisil.add(0);
  }

  dfs(1, 0, 0);
  reroot(1, 0);

  for (int i = 1; i <= n; ++i)
  {
    fout << ans[i] << '\n';
  }
}