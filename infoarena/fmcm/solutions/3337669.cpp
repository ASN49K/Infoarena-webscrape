#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

const int maxN = 355, maxM = 25005, inf = 0x3f3f3f3f;
int n, m, sursa, dest, dist[maxN], real_dist[maxN], fake_dist[maxN], pred[maxN], total_cost;
bool used[maxN], inQ[maxN];
struct mucie {
    int nxt, cap, flux, cost;
}lm[maxM];
vector <int> G[maxN];
queue <int> q;
struct haha4heap {
    int nod, cost;
    bool operator < (const haha4heap &other) const {
        return cost > other.cost;
    }
};
priority_queue <haha4heap> heap;

void bellman_ford()
{
    for(int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[sursa] = 0;
    q.push(sursa);
    inQ[sursa] = 1;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        inQ[curr] = 0;
        for(int ind : G[curr])
        {
            auto aux = lm[ind];
            if(aux.cap > 0 && dist[curr] + aux.cost < dist[aux.nxt])
            {
                dist[aux.nxt] = dist[curr] + aux.cost;
                if (!inQ[aux.nxt]) {
                    q.push(aux.nxt);
                }
            }
        }
    }
}

bool dijkstra()
{
    for(int i = 1; i <= n; i++)
    {
        real_dist[i] = dist[i];
        fake_dist[i] = inf;
        used[i] = 0;
    }
    dist[sursa] = 0;
    fake_dist[sursa] = 0;
    heap.push({sursa, 0});
    while(!heap.empty())
    {
        auto curr = heap.top();
        heap.pop();
        if(used[curr.nod])
            continue;
        used[curr.nod] = 1;
        for(int ind : G[curr.nod])
        {
            auto aux = lm[ind];
            if(aux.flux == aux.cap)
                continue;
            if(real_dist[curr.nod] + fake_dist[curr.nod] + aux.cost < real_dist[aux.nxt] + fake_dist[aux.nxt])
            {
                fake_dist[aux.nxt] = real_dist[curr.nod] + fake_dist[curr.nod] + aux.cost - real_dist[aux.nxt];
                pred[aux.nxt] = ind;
                dist[aux.nxt] = dist[curr.nod] + aux.cost;
                heap.push({aux.nxt, fake_dist[aux.nxt]});
            }
        }
    }
    if(fake_dist[dest] == inf)
        return 0;
    return 1;
}

int main()
{
    fin >> n >> m >> sursa >> dest;
    for(int i = 0; i < m; i++)
    {
        int x, y, c, z; /// capacitatea este c, costul este z
        fin >> x >> y >> c >> z;
        lm[2 * i] = {y, c, 0, z};
        lm[2 * i + 1] = {x, 0, 0, -z};
        G[x].push_back(2 * i);
        G[y].push_back(2 * i + 1);
    }
    bellman_ford();
    while(dijkstra())
    {
        int min_flux = inf;
        for(int x = dest; x != sursa; x = lm[pred[x]^1].nxt)
            min_flux = min(min_flux, lm[pred[x]].cap - lm[pred[x]].flux);
        for(int x = dest; x != sursa; x = lm[pred[x]^1].nxt)
        {
            int ind = pred[x];
            lm[ind].flux += min_flux;
            lm[ind^1].flux -= min_flux;
        }
        total_cost += min_flux * dist[dest];
    }
    fout << total_cost;
    return 0;
}
