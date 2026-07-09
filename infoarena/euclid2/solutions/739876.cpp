#include <cstdio>
using namespace std;
int a ,b,n,i;
int cmc(int X,int Y)
{
	while (X!=Y&&X&&Y)
	   if (X>Y) X%=Y;
	     else Y%=X;

	if (X) return X;
		 else return Y;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%ld",&n);
	
	for(i=1;i<=n;++i)
	{
	   scanf("%ld%ld",&a,&b);
	   
	   printf("%ld\n",cmc(a,b));
	}
	
	return 0;
}
