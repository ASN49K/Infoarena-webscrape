#include<stdio.h>

int cmmdc(int a, int b)
{
	while( (long long)a * b ){
		if( a > b) a = a % b;
		else b = b %a;
	}
	return a + b;
	
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n;
	scanf("%d", &n);
	for( int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a,b));
	}
		
	
	
	return 0;
}