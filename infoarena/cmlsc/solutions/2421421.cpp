#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N_MAX 1030

int a[N_MAX],b[N_MAX];

vector <int> hash[260];

int n,m,i,j;

struct cmp
{
	bool operator () (const int &a,const int &b) const
	{
		return a>b;
	}
};

vector <int> c;
vector <int> ::iterator it,it1;

vector <int> bin,l,sol;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);

	for(i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		hash[b[i]].push_back(i);
	}

	for(i=0;i<=256;i++)
		sort(hash[i].begin(),hash[i].end(),cmp());

	for(i=1;i<=n;i++)
		for(it=hash[a[i]].begin();it!=hash[a[i]].end();it++)
			c.push_back(*it);

	for(it1=c.begin();it1!=c.end();it1++)
	{
		it=lower_bound(bin.begin(),bin.end(),*it1);
		if(it!=bin.end())
		{
			*it=*it1;
			l.push_back(it-bin.begin()+1);
		}
		else
		{
			bin.push_back(*it1);
			l.push_back(bin.size());
		}
	}

	it=max_element(l.begin(),l.end());
	int i=it-l.begin(),val=*it;

	printf("%d\n",val);
	sol.push_back(b[c[i]]);

	for(--i;i>=0;i--)
	{
		if(l[i]==val-1)
		{
			--val;
			sol.push_back(b[c[i]]);
		}
	}

	for(;!sol.empty();sol.pop_back())
		printf("%d ",sol.back());

	return 0;
}
