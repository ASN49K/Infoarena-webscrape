#include<cstdio>
using namespace std;
int t,q,a,b;
void read()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
}

int euclid(int x,int y)
{
	int r;
	while(y)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}

void rez()
{
	for(q=1;q<=t;q++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",euclid(a,b));
	}
}

int main()
{
	read();
	rez();
	return 0;
}