#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const string txt = "fmcm";
const long long inf = 1e9;

ifstream f(txt + ".in");
ofstream g(txt + ".out");

long long n, m, sour, dest, ans, flow[400][400], cost[400][400];
long long idk[400], d[400], nd[400], t[400], viz[400];
vector<long long> v[400];

void bellman(long long node)
{
	for (long long i = 1; i <= n; i++) d[i] = inf;
	queue<long long> q; while (!q.empty()) q.pop();

	q.push(node); d[node] = 0;
	while (!q.empty())
	{
		long long node = q.front(); q.pop();
		for (auto x : v[node])
			if (d[node] != inf && d[x] < d[node] + cost[node][x])
				d[x] = d[node] + cost[node][x], q.push(x);
	}
}

bool dijkstra(long long node)
{
	priority_queue<pair<long long, long long>> h; while (!h.empty()) h.pop();
	for (long long i = 1; i <= n; i++) viz[i] = t[i] = 0, idk[i] = nd[i] = inf;

	h.push({ 0, node }); nd[node] = idk[node] = 0;
	while (!h.empty())
	{
		long long node = h.top().second; h.pop();
		if (viz[node]) continue;

		viz[node] = 1;
		for (auto x : v[node])
		{
			long long val = idk[node] + cost[node][x] + d[node] - d[x];
			if (flow[node][x] > 0 && idk[x] > val)
			{
				idk[x] = val; t[x] = node;
				nd[x] = nd[node] + cost[node][x];
				h.push({ -idk[x], x });
			}
		}
	}

	return viz[dest];
}

void max_flow()
{
	bellman(sour);
	while (dijkstra(sour))
	{
		for (long long i = 1; i <= n; i++) d[i] = nd[i];

		long long mini = (long long)1e9;
		for (long long i = dest; i != sour; i = t[i])
			mini = min(mini, flow[t[i]][i]);

		ans += mini * d[dest];

		for (long long i = dest; i != sour; i = t[i])
			flow[t[i]][i] -= mini, flow[i][t[i]] += mini;
	}
}

int main()
{
	f >> n >> m >> sour >> dest;
	for (long long i = 1; i <= m; i++) {
		long long x, y; f >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);

		f >> flow[x][y] >> cost[x][y];
		cost[y][x] = -cost[x][y];
	}

	max_flow();

	g << ans;
	return 0;
}