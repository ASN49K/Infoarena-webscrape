#include <stdio.h>

using namespace std;

int euclid ( int a , int b)
{
	if(!b)
		return a;
	if(b>a)
		return euclid ( b , a);
	if(a>b)
		return euclid ( b , a%b);
}

int main()
{
	freopen ("euclid2.in" , "r" , stdin);
	freopen ("euclid2.out" , "w" , stdout);
	int n,a,b;
	scanf( "%d", &n);
	for ( int i = 1 ; i <= n ; i++ )
	{
		scanf("%d %d", &a, &b);
		printf( "%d\n", euclid(a , b) );
		
	}
}