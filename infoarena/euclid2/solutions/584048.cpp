#include<fstream>
#include<cstdio>

using namespace std;

const int MaxT = 100001;
const char InFile[] = "euclid2.in";
const char OutFile[] = "euclid2.out";

int T;

int euclid(int a,int b)
{
	if( !b )
		return a;
		else
		return euclid(b,a%b);
}

int main()
{
	freopen( InFile , "r" , stdin );
	freopen( OutFile , "w" , stdout );
	scanf("%d" , &T );
	int a,b;
	while( T-- )
		{
			scanf("%d%d" , &a , &b);
			printf("%d\n" , euclid(a,b));
		}
	return 0;
}
