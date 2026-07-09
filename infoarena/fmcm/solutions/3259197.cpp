#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
ifstream f("fmcm.in");
ofstream g("fmcm.out");
int cap[355][355],cost[355][355],h[355],dist[355],parent[355],mincost;
bool inque[355];
int n,m,s,d;
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
            if(!inque[i]&&cap[x][i]&&h[i]>h[x]+cost[x][i])
        {
            h[i]=h[x]+cost[x][i];
            q.push(i);
            inque[i]=1;
        }
    }
}
void johnson()
{
    for(int i=1;i<=n;i++)
        for(auto j:v[i])
            cost[i][j]=cost[i][j]+h[i]-h[j];
}
bool dijkstra()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    memset(dist,127,sizeof(int)*(n+3));
    memset(parent,0,sizeof(int)*(n+3));
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty())
    {
        int x=pq.top().second, y=pq.top().first;
        pq.pop();
        if(dist[x]<y) continue;
        if(x==d) return true;
        for(auto i:v[x])
            if(cap[x][i]&&y+cost[x][i]<dist[i])
        {
            pq.push({y+cost[x][i],i});
            dist[i]=y+cost[x][i];
            parent[i]=x;
        }
    }
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
    johnson();
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
            tsoc+=(cost[parent[node]][node]+h[node]-h[parent[node]])*mincap;
            node=parent[node];
        }
        mincost+=tsoc;
    }
    g<<mincost;
    return 0;
}