#include<cstdio>
class euclid
{
private:
	int x,y,r;
public:
	void euclid1(int x, int y)
	{
		while (y)
		{
			r=x%y;
			x=y;
			y=r;
		}
		
		printf("%d\n", (x)? (x):(-1));
	}
	void citire(int &x, int &y)
	{
		scanf("%d%d",&x,&y);
	}
};
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int T;
	scanf("%d",&T);
	euclid *ab=new euclid;
	int a,b;
	while (T--)
	{
		ab->citire(a,b);
		ab->euclid1(a,b);
	}
	return 0;
}
