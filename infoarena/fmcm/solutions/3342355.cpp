#include<bits/stdc++.h>
#define nl '\n'
#define pii pair<int,int>
using namespace std;
const string file="fmcm";
ifstream f(file+".in");
ofstream g(file+".out");
//#define f cin
//#define g cout

struct flux {
    struct edge {
        int to,rez,cap,cost;
    };
    vector<vector<edge>>v;
    vector<int>dist,pot;
    vector<int>dad,dadedge;
    int n,s,t;
    flux(int _n, int _s, int _t) {
        n=_n,s=_s,t=_t;
        v.resize(n+1);
        dist.resize(n+1);
        pot.resize(n+1);
        dad.resize(n+1);
        dadedge.resize(n+1);
    }
    void add(int x, int y, int cap, int cost) {
        edge a={y,(int)v[y].size(),cap,cost};
        edge b={x,(int)v[x].size(),0,-cost};
        v[x].push_back(a);
        v[y].push_back(b);
    }
    void bellman() {
        fill(pot.begin(),pot.end(),INT_MAX);
        pot[s]=0;
        bool ok;
        for (int i=1; i<=n; ++i) {
            ok=0;
            for (int x=1; x<=n; ++x) {
                if (pot[x]==INT_MAX) continue;
                for (auto e:v[x]) {
                    if (pot[e.to]>pot[x]+e.cost) {
                        pot[e.to]=pot[x]+e.cost;
                        ok=1;
                    }
                }
            }
            if (!ok) break;
        }
    }
    bool dijkstra() {
        fill(dist.begin(),dist.end(),INT_MAX);
        dist[s]=0;
        priority_queue<pii,vector<pii>,greater<pii>>q;
        q.push({0,s});
        while (!q.empty()) {
            int cost=q.top().first;
            int x=q.top().second;
            q.pop();
            for (int i=0; i<v[x].size(); ++i) {
                edge &e=v[x][i];
                if (e.cap>0) {
                    int d=cost+e.cost+pot[x]-pot[e.to];
                    if (d<dist[e.to]) {
                        dist[e.to]=d;
                        dad[e.to]=x;
                        dadedge[e.to]=i;
                        q.push({d,e.to});
                    }
                }
            }
        }
        return dist[t]!=INT_MAX;
    }
    pii costflow() {
        bellman();
        int flow=0,cost=0;
        while (dijkstra()) {
            for (int i=1; i<=n; ++i) {
                if (dist[i]<INT_MAX) pot[i]+=dist[i];
            }
            if (pot[t]>=0) break;
            int flux=INT_MAX;
            for (int x=t; x!=s; x=dad[x]) {
                edge &e=v[dad[x]][dadedge[x]];
                flux=min(flux,e.cap);
            }
            for (int x=t; x!=s; x=dad[x]) {
                edge &e=v[dad[x]][dadedge[x]];
                e.cap-=flux;
                v[x][e.rez].cap+=flux;
                cost+=e.cost*flux;
            }
            flow+=flux;
        }
        return {flow,cost};
    }
};
int n,m,s,t;
int main(){
    f>>n>>m>>s>>t;
    flux fl(n,s,t);
    for (int i=1; i<=m; ++i) {
        int x,y,cap,cost;
        f>>x>>y>>cap>>cost;
        fl.add(x,y,cap,cost);
    }
    g<<fl.costflow().second;
    system("pause");
    return 0;
}