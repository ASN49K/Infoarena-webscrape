#include<cstdio>
#include<fstream>

using namespace std;

int T;
const char InFile[] = "euclid2.in";
const char OutFile[] = "euclid2.out";

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
	freopen( InFile , "r" , stdin );
	freopen( OutFile , "w" , stdout );
	scanf("%d" , &T );
	int a,b;
	for( ; T ; T-- )
		{
			scanf("%d%d" , &a , &b);
			printf("%d\n" , euclid(a,b));
		}
	return 0;
}
