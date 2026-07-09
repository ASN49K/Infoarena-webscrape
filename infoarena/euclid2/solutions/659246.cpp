#include<fstream>
#include<cstdio>

using namespace std;

int T,a,b;

int euclid(int a,int b)
{
	int r;
	r = a % b;
	while( r )
		{
			a = b;
			b = r;
			r = a % b;
		}
	return b;
}

int main()
{
	freopen("euclid2.in", "r" , stdin );
	freopen("euclid2.out" , "w" , stdout );
	scanf("%d" , &T );
	for( int i = 0 ; i < T ; i++ )
		{
			scanf("%d%d" , &a , & b);
			printf("%d\n" , euclid(a,b));
		}
	return 0;
}
