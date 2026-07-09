	#include<stdio.h>
	using namespace std;
	int  T , a , b;
	
	int euclid(int a , int b)
	{
		if(b==0)
			return a;
		else
			return euclid(b,a%b);
	}
	
	int main()
	{
		freopen("euclid2.in" , "r" , stdin );
		freopen("euclid2.out" , "w" , stdout );
		
		scanf("%d" , &T);
		
		for( int i = 1 ; i<= T ; ++i )
		{
			scanf("%d%d" , &a , &b );
			printf("%d\n" , euclid(a,b));
		}
	}
	