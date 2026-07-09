#include <bits/stdc++.h>
using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

const int INF = 2e9;

int n, m, s, d;
int maxflow, mincost;

vector<int> vis, parent, in_queue, dist, potential;
vector<vector<int>> adj_list;
vector<vector<int>> cap, flow, cost;

void read()
{
    fin >> n >> m >> s >> d;

    adj_list.assign(n + 5, {});
    cap.assign(n + 5, vector<int>(n + 5, 0));
    flow.assign(n + 5, vector<int>(n + 5, 0));
    cost.assign(n + 5, vector<int>(n + 5, 0));

    dist.assign(n + 5, INF);
    potential.assign(n + 5, 0);
    in_queue.assign(n + 5, 0);
    vis.assign(n + 5, 0);
    parent.assign(n + 5, 0);

    for (int i = 0; i < m; i++)
    {
        int x, y, c, z;
        fin >> x >> y >> c >> z;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);

        cap[x][y] = c;
        cost[x][y] = z;
        cost[y][x] = -z;   // residual edge cost
    }
}


void bellman_ford()
{
    // initial shortest paths to handle negative costs

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    queue<int> q;
    dist[s] = 0;
    q.push(s);
    in_queue[s] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        in_queue[curr] = 0;

        for (auto next : adj_list[curr])
        {
            if (cap[curr][next] > 0 &&
                dist[curr] + cost[curr][next] < dist[next])
            {
                dist[next] = dist[curr] + cost[curr][next];
                if (!in_queue[next])
                {
                    q.push(next);
                    in_queue[next] = 1;
                }
            }
        }
    }

    // initialize potentials
    for (int i = 1; i <= n; i++)
        if (dist[i] < INF)
            potential[i] = dist[i];
}


bool dijkstra()
{
    // dijkstra on reduced costs (cost + potential[u] - potential[v])

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        parent[i] = 0;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [cd, curr] = pq.top();
        pq.pop();

        if (cd != dist[curr])
            continue;

        for (auto next : adj_list[curr])
        {
            // reachable neighbour
            if (cap[curr][next] > flow[curr][next])
            {   
                // relax neighbour
                int w = cost[curr][next] + potential[curr] - potential[next]; // adapted cost
                if (dist[curr] + w < dist[next])
                {
                    dist[next] = dist[curr] + w;
                    parent[next] = curr;
                    pq.push({dist[next], next});
                }
            }
        }
    }

    // success
    return dist[d] < INF;
}

void solve()
{
    // preprocess the potentials
    bellman_ford();

    while (dijkstra())
    {
        // update potentials
        for (int i = 1; i <= n; i++)
            if (dist[i] < INF)
                potential[i] += dist[i];

        // find bottleneck
        int bottleneck = INF;
        int temp = d;
        while (temp != s)
        {
            bottleneck = min(bottleneck, 
                cap[parent[temp]][temp] - flow[parent[temp]][temp]);
            temp = parent[temp];
        }

        maxflow += bottleneck;
        mincost += bottleneck * potential[d];

        // augment flow
        temp = d;
        while (temp != s)
        {
            flow[parent[temp]][temp] += bottleneck;
            flow[temp][parent[temp]] -= bottleneck;
            temp = parent[temp];
        }
    }

    fout << mincost;
}

int main()
{
    read();
    solve();
    return 0;
}
