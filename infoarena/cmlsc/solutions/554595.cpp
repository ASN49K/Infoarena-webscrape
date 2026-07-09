#include<vector>
#include<cstdio>
using namespace std;

vector<int> a,b;
vector<int> k;
vector<vector<int> > sol;
int m,n;
int MAX = 0;

void print_sol()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			printf("%d ",sol[i][j]);
		printf("\n");
	}
}


int search(int x,int s)
{
	for(int i=s;i<=m;i++)
		if(a[i] == x)
			return i;
	return -1;
}

int getMax(int x, int y)
{
	int max=0;
	for(int i = 1;i<x;i++)
		for(int j=1;j<y;j++)
			if(sol[i][j] > max)
				max = sol[i][j];
				
	return max;
}

void compute()
{
	sol.resize(n+5);
	for(int i=0;i<=n+4;i++)
		sol[i].resize(m+5,0);
	for(int i=1;i<=n;i++)
	{
		int start = 1;
		int next=0;
		//printf("%d",a.size());
		while((next = search(b[i],start)) > 0)
		{
			//printf("n:%d\n",next);
			sol[i][next] = getMax(i,next)+1;
			start++;
		}
			
	}
		
	
	//print_sol();
}

void read(vector<int> &v, int n)
{
	v.push_back(-1);
	int no;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&no);
		v.push_back(no);
	}
	
	
}

int getSol(int i, int y)
{
	int max = 0, pos=0;
	for(int j=1;j<=y;j++)
		if(sol[i][j]>max)
		{
			max=sol[i][j];
			pos = j;
		}
	if(max)
		y = pos - 1;

	if(i>1)
		k.push_back(getSol(i-1,y));
	return a[pos];
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&m,&n);
	read(a,m);
	read(b,n);
	compute();
	k.clear();
	k.push_back(getSol(n,m));
	printf("%d\n",getMax(n+1,m+1));
	for(int i=0;i<k.size();i++)
		if(k[i]>0)
			printf("%d ",k[i]);
}
	
