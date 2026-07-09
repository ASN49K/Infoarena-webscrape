#include <stdio.h>
#include <stdlib.h>

int a,b;
int euclid (int a, int b)
{  
	if(!b)
		return a;
	return euclid(b, a%b);
}
	
int main ()
{   int t;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	
	scanf("%d", &t);
	while(t --)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", euclid(a,b));
	}
	return 0;
}
	
	