#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;

vector<int> a,b;
vector<int> k;
vector<vector<int> > sol;
int m,n;

int search(int x,int s,int l)
{
	for(int i=s;i<=m;i++)
	{
		
		if(sol[l-1][i] > sol[l][i-1])
			sol[l][i] = sol[l-1][i];
		else
			sol[l][i] = sol[l][i-1];
		if(a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

int getMax(int x, int y)
{
	int max=0;				
	for(int i=y-1;i>0;i--)
		if(sol[m+1][i]>max)
			max = sol[m+1][i];
	return sol[x-1][y-1];
}

void compute()
{
	sol.resize(n+5);
	sol[0].resize(m+5,0);
	for(int i=1;i<=n;i++)
	{
		sol[i].resize(m+5,0);
		int start = 1;
		int next=0;
		while((next = search(b[i],start,i)) > 0)
		{
			sol[i][next]=sol[i-1][next-1]+1;
			start=next+1;
		}
			
	}
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

int getSol(int x, int y)
{
	int i=x,j=y;
	
	while(sol[i][j-1] == sol[x][y])
		if(j>1)
			j--;
	while(sol[i-1][j] == sol[x][y])
		if(i>1)
			i--;
	if(i>1)
		k.push_back(getSol(i-1,j-1));
	return a[j];
			
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
	printf("%d\n",sol[n][m]);
	for(int i=0;i<k.size();i++)
		if(k[i]>0)
			printf("%d ",k[i]);
}
	
