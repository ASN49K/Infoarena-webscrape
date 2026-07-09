#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const string txt = "fmcm";
const int inf = 1e9;

ifstream f(txt + ".in");
ofstream g(txt + ".out");

int n, m, sour, dest, ans, flow[400][400], cost[400][400];
int idk[400], d[400], nd[400], t[400], viz[400];
vector<int> v[400];

void bellman(int node)
{
	for (int i = 1; i <= n; i++) d[i] = inf;
	queue<int> q; while (!q.empty()) q.pop();

	q.push(node); d[node] = 0;
	while (!q.empty())
	{
		int node = q.front(); q.pop();
		for (auto x : v[node])
			if (d[node] != inf && d[x] < d[node] + cost[node][x])
				d[x] = d[node] + cost[node][x], q.push(x);
	}
}

bool dijkstra(int node)
{
	priority_queue<pair<int, int>> h; while (!h.empty()) h.pop();
	for (int i = 1; i <= n; i++) viz[i] = t[i] = 0, idk[i] = nd[i] = inf;

	h.push({ 0, node }); nd[node] = idk[node] = 0;
	while (!h.empty())
	{
		int node = h.top().second; h.pop();
		if (viz[node]) continue;

		viz[node] = 1;
		for (auto x : v[node])
		{
			int val = idk[node] + cost[node][x] + d[node] - d[x];
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
		for (int i = 1; i <= n; i++) d[i] = nd[i];

		int mini = (int)1e9;
		for (int i = dest; i != sour; i = t[i])
			mini = min(mini, flow[t[i]][i]);

		ans += mini * d[dest];

		for (int i = dest; i != sour; i = t[i])
			flow[t[i]][i] -= mini, flow[i][t[i]] += mini;
	}
}

int main()
{
	f >> n >> m >> sour >> dest;
	for (int i = 1; i <= m; i++) {
		int x, y; f >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);

		f >> flow[x][y] >> cost[x][y];
		cost[y][x] = -cost[x][y];
	}

	max_flow();

	g << ans;
	return 0;
}