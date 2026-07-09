using namespace std;
#include<cstdio>
int t,a,b,c;

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(t;t;t--)
	{
		scanf("%d%d",&a,&b);
		while(b)
		{
			c=a%b;
			a=b;
			b=c;
		}
		printf("%d\n",a);
	}
	return 0;
}
			