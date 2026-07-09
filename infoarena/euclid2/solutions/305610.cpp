// euclid2.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
int main()
{	
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int i,t,a,b;
	scanf("%d", &t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d", &a, &b);
		while(a!=b)
		{
			if(a>b)
				a=a-b;
			else b=b-a;
		}
		printf("%d\n", a);
	}
	return 0;
}

