#include <bits/stdc++.h>

using namespace std;
ifstream fin("fmcm.in");
ofstream fout("fmcm.out");
typedef pair<int,int> pii;
const int INF=1e9;
int n,m,cap[355][355],cost[355][355],real_d[355],old_d[355],d[355],from[355],S,D,ans;
bool use[355];
vector<int> muchii[355];
void bellman()
{
	for(int i=1;i<=n;i++)
		old_d[i]=INF;
	old_d[S]=0;
	queue<int> coada;
	coada.push(S);
	while(!coada.empty())
	{
		int nod=coada.front();
		coada.pop();
		for(int i:muchii[nod])
			if(cap[nod][i]>0&&old_d[i]>old_d[nod]+cost[nod][i])
			{
				old_d[i]=old_d[nod]+cost[nod][i];
				coada.push(i);
			}
	}
}
bool flux()
{
	for(int i=1;i<=n;i++)
	{
		d[i]=INF;
		real_d[i]=INF;
		from[i]=0;
		use[i]=0;
	}
	real_d[S]=0;
	d[S]=0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({d[S],S});
	while(!pq.empty())
	{
		int nod=pq.top().second;
		pq.pop();
		if(use[nod])
			continue;
		use[nod]=1;
		for(int i:muchii[nod])
		{
			//cout<<i<<' '<<cap[nod][i]<<' '<<d[i]<<' '<<d[nod]+cost[nod][i]+old_d[nod]-old_d[i]<<'\n';
			if(cap[nod][i]>0&&d[i]>d[nod]+cost[nod][i]+old_d[nod]-old_d[i])
			{				
				d[i]=d[nod]+cost[nod][i]+old_d[nod]-old_d[i];
				real_d[i]=real_d[nod]+cost[nod][i];
				from[i]=nod;
				pq.push({d[i],i});
			}
		}
	}
	if(d[D]==INF)
		return 0;
	for(int i=1;i<=n;i++)
		old_d[i]=real_d[i];
	int minim=INF;
	for(int i=D;i!=S;i=from[i])
		minim=min(minim,cap[from[i]][i]);
	ans+=minim*real_d[D];
	for(int i=D;i!=S;i=from[i])
	{
		cap[from[i]][i]-=minim;
		cap[i][from[i]]+=minim;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	fin.tie(0);
	fin>>n>>m>>S>>D;
	for(int i=1;i<=m;i++)
	{
		int a,b,c,cst;
		fin>>a>>b>>c>>cst;
		muchii[a].push_back(b);
		muchii[b].push_back(a);
		cap[a][b]=c;
		cost[a][b]=cst;
		cost[b][a]=-cst;
	}
	bellman();
	while(flux());
	fout<<ans;
	return 0;
}
