#include<iostream>
#include<cstdio>
using namespace std;

int cmmdc ( int x , int y ) 
{
	while ( x != y ) 
	if ( x > y ) x = x - y;
	else y = y - x;
	 
return x;
}

int i , n , a , b ;

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&n);
	
	for( i = 1 ; i <= n ; ++ i )
	{
		scanf("%d %d",&a,&b);
		printf("%d\n", cmmdc ( a , b ) );
	}
	
	
	return 0;
}