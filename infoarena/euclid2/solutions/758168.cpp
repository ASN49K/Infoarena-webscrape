#include <stdio.h>

int euclid(int a, int b)
{
	int r;
	while(a != 0 && b != 0)
	{
		if(a >= b)
		{
			a = a-b;
			r = b;
		}
		else
		{
			b = b-a;
			r = a;
		}
	}
	return r;
}
int main()
{
	int A,B,k,i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n",euclid(A,B));
	}
	return 0;
}