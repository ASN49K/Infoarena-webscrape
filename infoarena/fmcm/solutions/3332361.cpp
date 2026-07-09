#include <fstream>
#include <vector>
#include <queue>

using namespace std;
const int nmax = 400, inf = 1e9;
const string txt = "fmcm";

ifstream f(txt + ".in");
ofstream g(txt + ".out");

struct ceva {
	int x, c;
};

int n, m, sour, dest, flow[nmax][nmax], ans, t[nmax], idk[nmax], d[nmax], nd[nmax], fr[nmax];
vector<ceva> v[nmax];

void bellman()
{
	queue<int> q; while (!q.empty()) q.pop();
	for (int i = 1; i <= n; i++) d[i] = inf;

	q.push(sour); d[sour] = 0;
	while (!q.empty())
	{
		int node = q.front(); q.pop();

		for (auto vec : v[node])
			if (d[node] != inf && flow[node][vec.x] > 0 && d[vec.x] > d[node] + vec.c) {
				d[vec.x] = d[node] + vec.c;
				q.push(vec.x);
			}
	}
}

bool dijkstra()
{
	priority_queue<pair<int, int>> h; while (!h.empty()) h.pop();
	for (int i = 1; i <= n; i++) fr[i] = t[i] = 0, nd[i] = idk[i] = inf;

	h.push({ 0, sour }); nd[sour] = idk[sour] = 0;
	while (!h.empty())
	{
		int node = h.top().second; h.pop();
		if (fr[node]) continue;

		fr[node] = 1;
		for (auto vec : v[node])
		{
			if (flow[node][vec.x] <= 0) continue;

			int val = idk[node] + vec.c + d[node] - d[vec.x];
			if (idk[vec.x] > val)
			{
				idk[vec.x] = val; t[vec.x] = node;
				nd[vec.x] = nd[node] + vec.c;
				h.push({ -val, vec.x });
			}
		}
	}
	
	for (int i = 1; i <= n; i++) d[i] = nd[i];
	return fr[dest];
}

void maxflow()
{
	bellman();
	while (dijkstra())
	{
		int mini = inf;
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
	for (int i = 1; i <= m; i++)
	{
		int x, y, cap, cos;
		f >> x >> y >> cap >> cos;
		v[x].push_back({ y, cos });
		v[y].push_back({ x, -cos });
		flow[x][y] = cap;
	}

	maxflow();

	g << ans;
	return 0;
}