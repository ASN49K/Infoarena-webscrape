#include <fstream>
#include <vector>
#include <queue>
#define pii pair<int, int>

using namespace std;

const string txt = "fmcm";
const int inf = 1e9;

ifstream f(txt + ".in");
ofstream g(txt + ".out");

int n, m, s, de, flow[400][400], cost[400][400], d[400], ans, fr[400], nd[400], t[400], idk[400];
priority_queue<pii> H;
vector<int> v[400];
vector<pii> edge;

void bellman()
{
    for (int i = 1; i <= n; i++) d[i] = inf;

    d[s] = 0;
    for(int i = 1; i <= n; i ++)
        for (auto e : edge)
        {
            int x = e.first, y = e.second, c = cost[x][y];
            if (d[x] != inf && d[y] > d[x] + c)
                d[y] = d[x] + c;
        }
}

int find_min()
{
    while (!H.empty() && fr[H.top().second]) H.pop();
    if (H.empty()) return -1;

    auto aux = H.top(); H.pop();
    return aux.second;
}

bool dijkstra()
{
    for (int i = 1; i <= n; i++) nd[i] = idk[i] = inf, fr[i] = t[i] = 0;
    while (!H.empty()) H.pop(); H.push({ 0, s }); nd[s] = idk[s] = 0;

    while (!H.empty())
    {
        int node = find_min(); 

        if (node == -1) break;

        fr[node] = 1;
        for(auto x : v[node])
        {
            int val = idk[node] + cost[node][x] + d[node] - d[x];

            if (flow[node][x] > 0 && idk[x] > val)
            {
                t[x] = node; idk[x] = val;
                nd[x] = nd[node] + cost[node][x];
                H.push({ -val, x });
            }
        }
    }

    return fr[de];
}

void maxflow()
{
    bellman();
    while (dijkstra())
    {
        for (int i = 1; i <= n; i++) d[i] = nd[i];

        int mini = inf;
        for (int i = de; i != s; i = t[i])
            mini = min(mini, flow[t[i]][i]);
    
        ans += mini * d[de];

        for (int i = de; i != s; i = t[i])
            flow[t[i]][i] -= mini, flow[i][t[i]] += mini;
    }
}

int main()
{
    f >> n >> m >> s >> de;
    for (int i = 1; i <= m; i++)
    {
        int x, y; 
        f >> x >> y; f >> flow[x][y] >> cost[x][y];
        v[x].push_back(y);
        v[y].push_back(x);

        cost[y][x] = -cost[x][y];
        edge.push_back({ x, y });
    }

    bellman(); maxflow();

    g << ans;
    return 0;
}