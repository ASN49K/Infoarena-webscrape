#include<cstdio>
class euclid2
{
public:
	int x, y;
	void init(int a, int b)
	{
		x=a;
		y=b;
	}
	int cmmdc();
	
};
int euclid2::cmmdc()
{
		int r=x;
		if (!y)
			return x;
		x=y;
		y=r%y;
		return cmmdc();
	}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b,m;
	scanf("%d",&m);
	euclid2 rez;
	while (m--)
	{
		scanf("%d%d",&a,&b);
		rez.init(a,b);
		printf("%d\n",rez.cmmdc());
	}

	return 0;
}
