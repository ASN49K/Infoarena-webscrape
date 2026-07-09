#include <stdio.h>

int cmmdc(int a, int b)
{
	while(a && b)
		if( a >= b )
			a %= b;
		else
			b %= a;
	return a | b;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",cmmdc(a,b));
	return 0;
}
