#include <cstdio>

using namespace std;

int main()
{
	freopen("euclid2.in","r",stdin);
		freopen("euclid2.out","w",stdout);
	
	int tests,a,b,r;
	
	scanf("%d",&tests);
	
	for(int i=1;i<=tests;++i)
	{
			scanf("%d%d",&a,&b);
			
			while(b)
			{
			
				 r = b;
				 b = a%b;
				 a = r;
			}
			
			printf("%d",a);
	}
		return 0;
}