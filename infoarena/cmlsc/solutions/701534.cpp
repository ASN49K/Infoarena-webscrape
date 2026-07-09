#include<fstream>
#include<algorithm>
#define maxn 50005
#define inf 1<<30

using namespace std;
struct graf
{
	int nod,cost;
	graf *next;
};
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
graf *a[maxn];
int h[maxn],poz[maxn],d[maxn];
int n,m,k;

int left_son(int nod)
{
	return 2*nod;
}

int right_son(int nod)
{
	return 2*nod+1;
}

void upheap(int nod)
{
	while(nod/2>0 && d[h[nod]]<d[h[nod/2]])
	{
		swap(poz[h[nod]],poz[h[nod/2]]);
		swap(h[nod],h[nod/2]);
		nod/=2;
	}
}

void downheap(int nod)
{
	int son=0;
	do
	{
		son=0;
		if(left_son(nod)<=k)
		  son=left_son(nod);
		if(right_son(nod)<=k && d[h[left_son(nod)]]>d[h[right_son(nod)]] )
		  son=right_son(nod);
		if(d[h[son]]>d[h[nod]]) son=0;
		if(son)
		{
			swap(poz[h[son]],poz[h[nod]]);
			swap(h[son],h[nod]);
			
			nod=son;
		}
	}while(son);
}

void dijkstra()
{
	for(int i=1;i<=n;i++)
		d[i]=inf,poz[i]=-1;
	d[1]=0;
	k=1;
	poz[1]=1;
	h[1]=1;
	while(k)
	{
		int min=h[1];
		h[1]=h[k];
		k--;
		poz[h[1]]=1;
		downheap(1);
		graf *t=a[min];
		while(t)
		{
			if(d[t->nod]>t->cost+d[min])
			{
				d[t->nod]=t->cost+d[min];
				if(poz[t->nod]==-1)
				{
					h[++k]=t->nod;
					poz[t->nod]=k;
					upheap(k);
				}
				else 
					upheap(poz[t->nod]);
			}
		t=t->next;
		}
	}
	
}
void add(int where,int what,int cost)
{
	graf *q=new graf;
	q->nod=what;
	q->cost=cost;
	q->next=a[where];
	a[where]=q;
}

void read()
{
	in>>n>>m;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		in>>x>>y>>z;
		add(x,y,z);
	}
}

int main()
{
	read();
	dijkstra();
	for(int i=2;i<=n;i++)
		if(d[i]==inf) out<<"0 ";
	else 
		out<<d[i]<<" ";
}