#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,T;

		scanf("%d",&T);



	for(int i = 0;i < T;i++)
	{
		scanf("%d %d",&a,&b);
	
	if(a == 0 || b == 0)
	{
		a = a + b;
	}
	else
	{
		while(a != b)
		{
			while(a > b)
			a = a - b;
			while(b > a)
			b = b - a;
		}

	}

	printf("%d\n",a);

	}


	return(0);
}
