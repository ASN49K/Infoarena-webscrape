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
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}

int cmmdc(int a,int b)
{
	if (b)
		return cmmdc(b,(a%b));
	return a;
}
			
	
