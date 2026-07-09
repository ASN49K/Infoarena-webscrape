#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

ifstream fin ("fmcm.in");
ofstream fout ("fmcm.out");

const int INF=2e9;
const int NMAX=355;

vector<pair<int,int>>v[NMAX];

int t[NMAX];
int flux[NMAX][NMAX];
int dist[NMAX];
bool viz[NMAX];

int n,m,s,d;

int bellman()
{
    int i;
    for(i=1;i<=n;i++)
    {
        viz[i]=false;
        dist[i]=INF;
    }
    queue<int>q;
    q.push(s);
    dist[s]=0;
    viz[s]=true;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        viz[p]=false;
        for(auto i:v[p])
        {
            if(flux[p][i.first]>0 && dist[i.first]>dist[p]+i.second)
            {
                dist[i.first]=dist[p]+i.second;
                if(!viz[i.first])
                {
                    q.push(i.first);
                    viz[i.first]=true;
                }
                t[i.first]=p;
            }
        }
    }
    return dist[d];
}

int main()
{
    int i,x,y,maxi=0,mini;
    bool ok=true;
    fin>>n>>m>>s>>d;
    for(i=1;i<=m;i++)
    {
        int cost,cap;
        fin>>x>>y>>cap>>cost;
        v[x].push_back(make_pair(y,cost));
        v[y].push_back(make_pair(x,-cost));
        flux[x][y]=cap;
    }
    while(true)
    {
        mini=INF;
        int suma=bellman();
        if(suma==INF)
            break;
        x=d;
        while(x!=s)
        {
            mini=min(mini,flux[t[x]][x]);
            x=t[x];
        }
        x=d;
        while(x!=s)
        {
            flux[t[x]][x]-=mini;
            flux[x][t[x]]+=mini;
            x=t[x];
        }
        maxi+=mini*suma;
    }
    fout<<maxi;
    return 0;
}