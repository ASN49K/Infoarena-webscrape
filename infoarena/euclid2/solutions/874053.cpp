#include <cstdio>
using namespace std;


int N;
long long a,b,r;

int main (void) { 
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	
	scanf("%d",&N);
	
	for(; N ; N--)
	{
		scanf("%lld%lld",&a,&b);
		if( b > a) 
			a = b;
		/////////
		while ( b )
		{
			r = a%b;
			a = b;
			b = r;
		}
		/////////
		printf("%lld\n",b);
	}
}	