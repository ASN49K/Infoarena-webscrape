#include <cstdio>

using namespace std;

inline int CMMDC (int a,int b)
{
	int r=a%b;
	while(r)
	{
		a=b;b=r;r=a%b;
	}
	return b;
}

int main()
{
	int t,i,x,y;
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	scanf("%d", &t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d", &x,&y);
		printf("%d\n", CMMDC(x,y));
	}
	return 0;
}
