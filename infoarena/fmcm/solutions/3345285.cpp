#include <bits/stdc++.h>
#define NMAX 410
using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

int N, M, S, T, a, b, c, d, ok, C[NMAX][NMAX], Cost[NMAX][NMAX], F[NMAX][NMAX], dist[NMAX], parent[NMAX];
vector <int> G[NMAX];
bool in_queue[NMAX];

long long SPFA()
{
  for(int i = 1; i <= N; i++)
  {
    dist[i] = 2e9;
    parent[i] = -1;
  }
  dist[S] = 0;
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
        if(in_queue[e] == false)
        {
          in_queue[e] = true;
          q.push(e);
        }
      }
    }
  }
  if(dist[T] != 2e9)
  {
    int path_flow = 2e9;
    ok = 1;
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


  fin >> N >> M >> S >> T;
  for(int i = 1; i <= M; i++)
  {
    fin >> a >> b >> c >> d;
    G[a].push_back(b);
    G[b].push_back(a);

    C[a][b] = c;
    Cost[a][b] = d;
    Cost[b][a] = -d;
  }

  long long ans = 0;
  ok = 1;
  while(ok){
    ok = 0;
    ans += SPFA();
  }
  fout << ans;
  return 0;

}
