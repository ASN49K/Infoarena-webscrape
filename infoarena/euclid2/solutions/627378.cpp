#include <cstdio>

using namespace std;

int t,a,b;

int cmmdc(int a,int b)
{
	int c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

int main()
{
	freopen("euclid2.in","rw",stdin);
	freopen("euclid2.out","wt",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
			printf("%d\n",cmmdc(a,b));
		else printf("%d\n",cmmdc(b,a));
	}
	return 0;
}

