#include <bits/stdc++.h>

namespace fluxMaxCostMin{
using namespace std;
#ifdef fakeFILES
std::ifstream fin("input.in");
std::ofstream fout("input.out");
#else
std::ifstream fin("fmcm.in");
std::ofstream fout("fmcm.out");
#endif

int const MAXN = 355, INF = 1e9;
int N, M, S, D; /// nr vertices, edges, start and destination.
int C[MAXN][MAXN], Cst[MAXN][MAXN]; /// capacity and cost
vector<int> g[MAXN]; /// graph
int F, FCst; /// flow and flow cost.

int old_d[MAXN]; /// distance in graph without capacities.

int d[MAXN], real_d[MAXN], p[MAXN];/// distance (positive), real distance, parent
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > H;
inline bool dijkstra()
{
    fill(d,d+MAXN,INF);
    d[S] = 0; real_d[S] = 0;
    H.emplace(d[S], S);

    while(!H.empty())
    {
        int cst = H.top().first, nod = H.top().second;
        H.pop();

        if (d[nod] < cst)
            continue;

        vector<int> :: iterator it;
        for (it = g[nod].begin(); it != g[nod].end(); it++)
            if (C[nod][*it]) /// if it has remaning capacity
            {
                int new_d = d[nod] + Cst[nod][*it]; /// normal Dijkstra
                new_d+= old_d[nod] - old_d[*it]; /// to make sure it's positive.
                if (new_d < d[*it])
                {
                    d[*it] = new_d;
                    real_d[*it] = real_d[nod] + Cst[nod][*it];
                    p[*it] = nod;
                    H.emplace(d[*it], *it);
                }
            }
    }
    /// void* memcpy( void* dest, const void* src, std::size_t count );
    /// memcpy(old_d, real_d, sizeof(d)); /// ????


    /// normal flow behaviour:
    if (d[D] == INF)
        return false;

    int Min = INF, curCst = 0;
    for (int aux = D; aux != S; aux = p[aux])
        Min = min(Min, C[p[aux]][aux]),
        curCst += Cst[p[aux]][aux];

    F += Min;
    FCst += Min * real_d[D];

    for (int aux = D; aux != S; aux = p[aux])
        C[p[aux]][aux] -= Min,
        C[aux][p[aux]] += Min;

    return true;
}

bool vizQ[MAXN];
queue<int> Q; /// order of updated nodes.
inline bool bellmanFord()
{ /// bellman ford with queue. (doesn't check for negative cycle!)
    fill(old_d,old_d+MAXN,INF);
    old_d[S] = 0;
    Q.push(S);
    vizQ[S] = true;
    for (; !Q.empty(); Q.pop())
    {
        vector<int> :: iterator it;
        int i = Q.front();
        vizQ[i] = false;

        for (it = g[i].begin(); it != g[i].end(); it++)
            if (C[i][*it])
            {
                if (old_d[i] + Cst[i][*it] >= old_d[*it])
                    continue;

                old_d[*it] = old_d[i] + Cst[i][*it];
                if (vizQ[*it])
                    continue;

                vizQ[*it] = true;
                Q.push(*it);
            }
    }

    if (old_d[D] == INF)
        return false;

    return true;
}

int run()
{
    fin >> N >> M >> S >> D;
    while(M--)
    {
        int x, y;
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        fin >> C[x][y] >> Cst[x][y];
        Cst[y][x] = -Cst[x][y];
    }

    F = FCst = 0;
    bellmanFord();
    for (; dijkstra(); ); /// the flow algorithm :)

    fout << FCst;
    return 0;
}
}
int main()
{
    fluxMaxCostMin::run();
}
