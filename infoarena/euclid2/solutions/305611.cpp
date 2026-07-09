// euclid2.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
int main()
{	
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int i,t,a,b,r;
	scanf("%d", &t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d", &a, &b);
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		printf("%d\n", a);
	}
	return 0;
}

