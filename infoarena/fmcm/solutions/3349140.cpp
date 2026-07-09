#include <cstdio>
#include <cassert>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 355

int N, M, S, D;
int C[MAXN][MAXN], Cst[MAXN][MAXN];
vector<int> con[MAXN];
int F, FCst;

int old_d[MAXN]; char inQ[MAXN];
queue<int> Q;

int d[MAXN], real_d[MAXN], p[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > H;

inline bool dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[S] = 0; real_d[S] = 0;
    H.push(make_pair(d[S], S));

    for (; !H.empty(); )
    {
        int cst = H.top().first, nod = H.top().second;
        H.pop();
        if (d[nod] != cst)
            continue;

        vector<int> :: iterator it;
        for (it = con[nod].begin(); it != con[nod].end(); it++)
            if (C[nod][*it])
            {
                int new_d = d[nod] + Cst[nod][*it] + old_d[nod] - old_d[*it];
                if (new_d < d[*it])
                {
                    d[*it] = new_d;
                    real_d[*it] = real_d[nod] + Cst[nod][*it];
                    p[*it] = nod;
                    H.push(make_pair(d[*it], *it));
                }
            }
    }
    memcpy(old_d, real_d, sizeof(d));
    if (d[D] == 0x3f3f3f3f)
        return false;

    int Min = 0x3f3f3f3f, curCst = 0;
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

inline bool bellmanFord()
{
    memset(old_d, 0x3f, sizeof(old_d));
    old_d[S] = 0;

    for (Q.push(S), inQ[S] = 1; !Q.empty(); Q.pop())
    {
        vector<int> :: iterator it;
        int i = Q.front();
        inQ[i] = 0;

        for (it = con[i].begin(); it != con[i].end(); it++)
            if (C[i][*it])
            {
                if (old_d[i] + Cst[i][*it] >= old_d[*it])
                    continue;

                old_d[*it] = old_d[i] + Cst[i][*it];
                if (inQ[*it])
                    continue;

                inQ[*it] = 1;
                Q.push(*it);
            }
    }

    if (old_d[D] == 0x3f3f3f3f)
        return false;

    return true;
}

int main()
{
    freopen("fmcm.in", "rt", stdin);
    freopen("fmcm.out", "wt", stdout);

    assert(scanf("%d %d %d %d", &N, &M, &S, &D) == 4);
    assert(1 <= N && N <= 350);
    assert(1 <= M && M <= 12500);
    assert(1 <= S && S <= N);
    assert(1 <= D && D <= N);
    assert(S != D);

    for (; M; M--)
    {
        int x, y;
        assert(scanf("%d %d ", &x, &y) == 2);
        assert(1 <= x && x <= N);
        assert(1 <= y && y <= N);
        assert(x != y && !C[x][y] && !Cst[x][y] && !C[y][x] && !Cst[y][x]);
        assert(x != D && y != S);
        con[x].push_back(y);
        con[y].push_back(x);

        assert(scanf("%d %d", C[x] + y, Cst[x] + y) == 2);
        assert(1 <= C[x][y] && C[x][y] <= 10000);
        assert(-1000 <= Cst[x][y] && Cst[x][y] <= 1000);
        Cst[y][x] = -Cst[x][y];
    }

    F = FCst = 0;
    bellmanFord();
    for (; dijkstra(); );

    printf("%d\n", FCst);
    return 0;
}