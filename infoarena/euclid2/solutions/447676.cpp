#include<cstdio>

using namespace std;

int a,b,n,i;

int cmmdc(int a,int b);

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		printf("%d",cmmdc(a,b));
	}
	return 0;
}

int cmmdc(int a,int b)
{
	if (b)
		return (b,(a%b));
	return a;
}
			
	
