#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
ifstream f("fmcm.in");
ofstream g("fmcm.out");
int cap[355][355],cost[355][355],h[355],dist[355],parent[355],mincost;
bool inque[355];
int n,m,s,d,operatii;
vector<int> v[355];
void bellmanford()
{
    queue<int> q;
    memset(h,127,sizeof(int)*(n+3));
    q.push(s);
    h[s]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        inque[x]=0;
        for(auto i:v[x])
            if(cap[x][i]&&h[i]>h[x]+cost[x][i])
        {
            h[i]=h[x]+cost[x][i];
            if(!inque[i])
            {
                q.push(i);
                inque[i]=1;
            }
        }
    }
}
bool dijkstra()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int realdist[355];
    memset(dist,127,sizeof(int)*(n+3));
    pq.push({0,s});
    dist[s]=realdist[s]=0;
    while(!pq.empty())
    {
        int x=pq.top().second, y=pq.top().first;
        pq.pop();
        if(dist[x]!=y) continue;
        for(auto i:v[x]){operatii++;
            if(cap[x][i]&&y+cost[x][i]+h[x]-h[i]<dist[i])
        {
            pq.push({y+cost[x][i]+h[x]-h[i],i});
            dist[i]=y+cost[x][i]+h[x]-h[i], realdist[i]=realdist[x]+cost[x][i];
            parent[i]=x;
        }}
    }
    memcpy(h,realdist,sizeof h);
    if(dist[d]!=dist[0]) return true;
    return false;
}
int main()
{
    f>>n>>m>>s>>d;
    for(int i=1;i<=m;i++)
    {
        int a,b,c,d;
        f>>a>>b>>c>>d;
        cap[a][b]=c, cost[a][b]=d, cost[b][a]=-d;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bellmanford();
    while(dijkstra())
    {
        int node=d, mincap=dist[0],tsoc=0;
        while(parent[node])
        {
            mincap=min(mincap,cap[parent[node]][node]);
            node=parent[node];
        }
        node=d;
        while(parent[node])
        {
            cap[parent[node]][node]-=mincap, cap[node][parent[node]]+=mincap;
            tsoc+=cost[parent[node]][node]*mincap;
            node=parent[node];
        }
        mincost+=tsoc;
    }
    g<<mincost;
    //g<<" "<<operatii;
    return 0;
}