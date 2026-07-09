#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long n,m;
long c[1026][1026];
vector <long> a;
vector <long> b;
vector <long> sol;
void read()
{
	long i,temp;
	scanf("%ld%ld",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&temp);
		a.push_back(temp);
	}
	for (i=1;i<=m;i++)
	{
		scanf("%ld",&temp);
		b.push_back(temp);
	}
}

long max (long x , long y)
{
	if (x>y)
		return x;
	return y;
}

inline bool cmp (long v  ,long w)
{
	if (v<w)
		return true;
	return false;
}

void rez()
{
	long i,j,x,y,temp1,temp2;
	vector <long> :: iterator it;
	vector <long> :: iterator jt;
	for (i=1,it=a.begin();i<=n && it!=a.end();i++,++it)
		for (j=1,jt=b.begin();j<=m && jt!=b.end();j++,++jt)
		{
			if (*it==*jt)
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i][j-1],c[i-1][j]);
		}
	printf("%ld\n",c[n][m]);
	x=n;
	it=a.end()-1;
	jt=b.end()-1;
	y=m;
	while (x && y)
	{
		temp1=*it;
		temp2=*jt;
		if (temp1==temp2)
		{
			x--;
			y--;
			sol.push_back(temp1);
			--it;
			--jt;
		}
		else
		{
			if (c[x][y-1]>c[x-1][y])
			{
				y--;
				--jt;
			}
			else
			{
				x--;
				--it;
			}
		}
	}
	sort(sol.begin(),sol.end(),cmp);
	for (it=sol.begin();it!=sol.end();it++)
		printf("%ld ",*it);
	printf("\n");
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	read();
	rez();
	return 0;
}