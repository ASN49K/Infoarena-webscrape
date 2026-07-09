#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

ifstream cin("fmcm.in");
ofstream cout("fmcm.out");

int n,m,s,dd,rasp;
int cap[351][351];
int cost[351][351];
int rd[351];
int inad[351];
int d[351];
int u[351];
int viz[351];
vector<int> v[351];
deque<int> q;

void bellman_ford(){
    int i,nod;
	for(i=1;i<=n;i++) inad[i]=1e9;
	inad[s]=0;
	q.push_back(s);
	while(!q.empty()){
		nod=q.front();q.pop_front();
		for(auto it:v[nod]){
			if(cap[nod][it]>0 && inad[it]>inad[nod]+cost[nod][it]){
				inad[it]=inad[nod]+cost[nod][it];
				q.push_back(it);
			}
		}
	}

}

int flux(){
    int i,min1=1e9,nod;
    for(i=1;i<=n;i++){
		d[i]=rd[i]=1e9;
        viz[i]=u[i]=0;
    }
    rd[s]=d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
    q1.push({d[s],s});
    while(!q1.empty()){
		nod=q1.top().second;
		q1.pop();
		if(viz[nod]) continue;
		viz[nod]=1;
		for(auto it:v[nod]){
			if(cap[nod][it]>0 && d[it]>d[nod]+cost[nod][it]+inad[nod]-inad[it]){
				d[it]=d[nod]+cost[nod][it]+inad[nod]-inad[it];
				rd[it]=rd[nod]+cost[nod][it];
				u[it]=nod;
				q1.push({d[it],it});
			}
		}
	}
	if(d[dd]==1e9) return 0;
	for(i=1;i<=n;i++) inad[i]=rd[i];
	for(i=dd;i!=s;i=u[i])
		min1=min(min1,cap[u[i]][i]);
	rasp+=min1*rd[dd];
	for(i=dd;i!=s;i=u[i]){
		cap[u[i]][i]-=min1;
		cap[i][u[i]]+=min1;
	}
	return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int i,a,b,c,c1,aux;
	cin>>n>>m>>s>>dd;
	for(i=1;i<=m;i++){
        cin>>a>>b>>c>>c1;
        cap[a][b]=c;
        v[a].push_back(b);v[b].push_back(a);
		cost[a][b]=c1;cost[b][a]=-c1;
	}
	bellman_ford();
	while(true){
        aux=flux();
        if(!aux) break;
	}
	cout<<rasp;
    return 0;
}
