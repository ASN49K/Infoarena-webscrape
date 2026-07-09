#include <fstream>
#include <queue>
using namespace std;
ifstream cin("fmcm.in");
ofstream cout("fmcm.out");
const int N=351;
int n,m,sursa,dest;
long long flow[N][N],capacitate[N][N];
vector<pair<int,int>>adj[N];
long long dist[N],potential[N],muchie[N][N];
int de_unde[N];
bool djikstra()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,sursa});
    dist[sursa]=0;
    while(!pq.empty())
    {
        int nod=pq.top().second;
        long long cost=pq.top().first;
        //cout<<nod<<" "<<cost<<'\n';
        pq.pop();
        if(cost>dist[nod])
            continue;
        for(auto [u,c]:adj[nod])
        {
            //cout<<u<<" "<<c<<" "<<capacitate[nod][u]<<'\n';
            if(flow[nod][u]>0&&cost+c+potential[nod]-potential[u]<dist[u])
            {
                de_unde[u]=nod;
                dist[u]=cost+c+potential[nod]-potential[u];
                pq.push({dist[u],u});
            }
        }
    }

    if(dist[dest]==1e15)
        return false;

    for(int i=1; i<=n; i++)
    {
        potential[i]=dist[i]+potential[i]-potential[sursa];
        dist[i]=1e15;
    }
    return true;
}
long long ans=0;
void drum()
{
    long long mxf=1e15;
    int nod=dest;
    while(nod!=sursa)
    {
        mxf=min(mxf,flow[de_unde[nod]][nod]);
        nod=de_unde[nod];
    }

    nod=dest;
    while(nod!=sursa)
    {
        ans+=mxf*muchie[de_unde[nod]][nod];
        flow[de_unde[nod]][nod]-=mxf;
        flow[nod][de_unde[nod]]+=mxf;
        nod=de_unde[nod];
    }
}
int main()
{
    cin>>n>>m;
    cin>>sursa>>dest;
    for(int i=1; i<=m; i++)
    {
        int a,b,cost,flux;
        cin>>a>>b>>flux>>cost;
        capacitate[a][b]+=flux;
        flow[a][b]+=flux;
        adj[a].push_back({b,cost});
        adj[b].push_back({a,-cost});
        muchie[a][b]=cost;
        muchie[b][a]=-cost;
    }
    queue<int>q;
    for(int i=1; i<=n; i++)
        dist[i]=1e15;
    dist[sursa]=0;
    q.push(sursa);
    while(!q.empty())
    {
        int nod=q.front();
        for(auto [u,c]:adj[nod])
        {
            if(flow[nod][u]!=0 &&dist[u]>dist[nod]+c)
            {
                dist[u]=dist[nod]+c;
                q.push(u);
            }
        }
        q.pop();
    }
    for(int i=1; i<=n; i++)
    {
        potential[i]=dist[i];
        dist[i]=1e15;
    }
    while(djikstra())
    {
        //cout<<"proooooooooooooost"<<'\n';
        drum();
    }
    cout<<ans<<'\n';
    return 0;
}
