#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const char InFile[]="apm2.in";
const char OutFile[]="apm2.out";
const int MaxN=10111;
const int LogMaxN=16;

ifstream fin(InFile);
ofstream fout(OutFile);

struct Edge
{
	Edge(int x=0, int y=0, int cost=0):x(x),y(y),cost(cost){}
	int x,y,cost;
};

struct Edge_cmp
{
	inline bool operator() (const Edge &a, const Edge &b)
	{
		return a.cost<b.cost;
	}
};

struct EdgeTo
{
	EdgeTo(int to=0, int cost=0):to(to),cost(cost){}
	int to,cost;
};

int N,M,Q,PMD[MaxN],x,y,cost,depth,niv[MaxN],sc[MaxN][LogMaxN],s[MaxN][LogMaxN];
vector<Edge> V;
vector<EdgeTo> A[MaxN];

void DFS(int nod, int father=0, int fcost=0)
{
	s[nod][0]=father;
	sc[nod][0]=fcost;

	++depth;
	niv[nod]=depth;
	
	/*for(register int k=1;k<16;++k)
	{
		s[nod][k]=s[s[nod][k-1]][k-1];
		sc[nod][k]=max(sc[nod][k-1],sc[s[nod][k-1]][k-1]);
	}*/

	for(vector<EdgeTo>::iterator it=A[nod].begin();it!=A[nod].end();++it)
	{
		if(!niv[it->to])
		{
			DFS(it->to,nod,it->cost);
		}
	}
	--depth;
}

inline void PMDInit()
{
	for(register int i=1;i<=N;++i)
	{
		PMD[i]=-1;
	}
}

inline int PMDFind(int x)
{
	int t=x;
	while(PMD[t]>0)
	{
		t=PMD[t];
	}

	/*while(x!=t)
	{
		int aux=PMD[x];
		PMD[x]=t;
		x=aux;
	}*/

	return t;
}

inline bool PMDUnified(int x, int y)
{
	return PMDFind(x)==PMDFind(y);
}

inline void PMDUnify(int x, int y)
{
	int rx=PMDFind(x);
	int ry=PMDFind(y);
	if(rx!=ry)
	{
		if(PMD[rx]<PMD[ry])
		{
			PMD[rx]+=PMD[ry];
			PMD[ry]=rx;
		}
		else
		{
			PMD[ry]+=PMD[rx];
			PMD[rx]=ry;
		}
	}
}

inline void Kruskal()
{
	sort(V.begin(),V.end(),Edge_cmp());
	PMDInit();
	for(vector<Edge>::iterator it=V.begin();it!=V.end();++it)
	{
		if(!PMDUnified(it->x,it->y))
		{
			PMDUnify(it->x,it->y);
			A[it->y].push_back(EdgeTo(it->x,it->cost));
			A[it->x].push_back(EdgeTo(it->y,it->cost));
		}
	}
}

inline int GetMaxCostBrute(int x, int y)
{
	if(niv[y]<niv[x])
	{
		swap(x,y);
	}
	int maxCost=0;
	while(niv[x]<niv[y])
	{
		maxCost=max(maxCost,sc[x][0]);
		x=s[x][0];
	}
	while(x!=y)
	{
		maxCost=max(maxCost,sc[x][0]);
		maxCost=max(maxCost,sc[y][0]);
		x=s[x][0];
		y=s[y][0];
	}
	
	return maxCost;
}
inline int GetMaxCost(int x, int y)
{
	if(niv[y]<niv[x])
	{
		swap(x,y);
	}
	int maxCost=0;
	for(register int k=15;k>-1;--k)
	{
		if(niv[s[x][k]]<=niv[y])
		{
			maxCost=max(maxCost,sc[x][k]);
			x=s[x][k];
		}
	}
	for(register int k=15;k>-1;--k)
	{
		if(s[x][k]!=s[y][k])
		{
			maxCost=max(maxCost,sc[x][k]);
			maxCost=max(maxCost,sc[y][k]);
			x=s[x][k];
			y=s[y][k];
		}
	}
	
	return max(max(sc[x][0],sc[y][0]),maxCost);
}
int main()
{
	niv[0]=1<<30;
	fin>>N>>M>>Q;
	for(register int i=1;i<=M;++i)
	{
		fin>>x>>y>>cost;
		V.push_back(Edge(x,y,cost));
	}
	Kruskal();
	DFS(1);
	for(register int i=1;i<=Q;++i)
	{
		fin>>x>>y;
		fout<<GetMaxCostBrute(x,y)-1<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
