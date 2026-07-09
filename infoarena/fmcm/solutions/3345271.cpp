#include <fstream>
#include <vector>
#include <queue>
#define NMAX 355
using namespace std;

ifstream cin("fmcm.in");
ofstream cout("fmcm.out");

long long N, M, S, T, a, b, c, d, C[NMAX][NMAX], Cost[NMAX][NMAX], F[NMAX][NMAX], dist[NMAX], parent[NMAX], in_queue[NMAX];
vector <int> G[NMAX];

long long SPFA()
{
  for(int i = 1; i <= N; i++)
  {
    dist[i] = 2e18;
    parent[i] = -1;
  }
  dist[S] = 0;
  parent[S] = 0;
  queue <int> q;
  q.push(S);
  in_queue[S] = true;
  while(q.size())
  {
    int acc = q.front();
    in_queue[acc] = false;
    q.pop();

    for(auto e : G[acc])
    {
      if(C[acc][e] - F[acc][e] > 0 and dist[e] > dist[acc] + Cost[acc][e])
      {
        dist[e] = dist[acc] + Cost[acc][e];
        parent[e] = acc;
        if(in_queue[e] == 0)
        {
          in_queue[e] = 1;
          q.push(e);
        }
      }
    }
  }
  if(dist[T] != 2e18)
  {
    long long path_flow = 2e9;
    for(int i = T; i != S; i = parent[i])
      path_flow = min(path_flow, C[parent[i]][i] - F[parent[i]][i]);

    for(int i = T; i != S; i = parent[i])
    {
      F[parent[i]][i] += path_flow;
      F[i][parent[i]] -= path_flow;
    }
    return path_flow * dist[T];
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

  long long ans = 0;
  while(long long cost_min = SPFA()){
    ans += cost_min;
  }
  cout << ans;
  return 0;

}
