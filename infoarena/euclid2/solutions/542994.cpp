#include<cstdio>
using namespace std;

long cmmdc(long a, long b);

long cmmdc(long a, long b)
{
	if(!b) return a;
	return cmmdc(b,a%b);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	int n;
	long a, b;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%ld %ld",&a,&b);
		printf("%ld\n",cmmdc(a,b));
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}


