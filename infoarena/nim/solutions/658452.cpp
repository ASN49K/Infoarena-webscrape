#include<stdio.h>

int S, x, n, T ; 

int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	
	scanf("%d",&T);
	
	for( ; T--; )
	{
		scanf("%d",&n);
		
		S = 0 ; 
		for( ; n-- ; )
			scanf("%d",&x), S ^= x ; 
		
		if ( S ) printf("DA\n");
		else	 printf("NU\n");
	}
	
	return 0 ; 
}