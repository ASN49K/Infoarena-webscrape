#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#define NMAX 355
#define INF 1e9
#define INFLL 2e18
using namespace std;
ifstream cin("fmcm.in");
ofstream cout("fmcm.out");

int N, M, a, b, c, d, S, T, C[NMAX][NMAX], F[NMAX][NMAX], Cost[NMAX][NMAX], idx[NMAX], vis[NMAX];
long long dist[NMAX];
bool in_queue[NMAX];
vector <int> G[NMAX];

bool bfs()
{
  for(int i = 1; i <= N ;i++)
    dist[i] = INFLL;

  dist[S] = 0;
  queue <int> q;
  q.push(S);
  in_queue[S] = true;

  while(q.size())
  {
    int acc = q.front();
    q.pop();
    in_queue[acc] = false;

    for(auto e : G[acc])
    {
      if(dist[e] > dist[acc] + Cost[acc][e] and C[acc][e] - F[acc][e] > 0)
      {
        dist[e] = dist[acc] + Cost[acc][e];
        if(!in_queue[e]){
          in_queue[e] = true;
          q.push(e);
        }
      }
    }
  }
  if(dist[T] == INFLL)
    return false;
  return true;
}

int dfs(int acc, int pushed, long long &cost_min)
{
  if(acc == T or pushed == 0)
    return pushed;

  vis[acc] = 1;
  for( ; idx[acc] < G[acc].size(); idx[acc]++)
  {
    int e = G[acc][idx[acc]];

    if(dist[e] != dist[acc] + Cost[acc][e] or C[acc][e] - F[acc][e] == 0 or vis[e])
      continue;

    int path_flow = dfs(e , min(pushed, C[acc][e] - F[acc][e]), cost_min);

    if(path_flow == 0)
      continue;

    F[acc][e] += path_flow;
    F[e][acc] -= path_flow;
    cost_min += path_flow * Cost[acc][e];
    vis[acc] = 0;
    return path_flow;
  }
  return 0;
}
int main()
{
  cin >> N >> M >> S >> T;
  for(int i = 1; i <= M; i++)
  {
    cin >> a >> b >> c >> d;
    G[a].push_back(b);
    G[b].push_back(a);
    C[a][b] = c;
    Cost[a][b] = d;
    Cost[b][a] = -d;
  }

  int max_flow = 0;
  long long cost_min = 0;
  while(bfs())
  {
    memset(idx, 0, sizeof(idx));
    memset(vis, 0, sizeof(vis));
    while(int pushed = dfs(S, INF, cost_min)){
      max_flow += pushed;
    }
  }
  //cout << max_flow << '\n';
  cout << cost_min ;
  return 0;
}
