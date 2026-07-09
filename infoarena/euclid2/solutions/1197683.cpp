#include <iostream>

using namespace std;

int cmmdc(int a, int b) 
{
	while(1)
	{
		if(!a)
		   return b;
		else if(!b)
		   return a;
		else
		{
			if(a > b)
			  a -= b;
			else
			  b -= a;
		}
	}
}



int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	int max;
	int a, b;
	
	scanf("%d", &max);

	for(int i = 0; i < max; ++i)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	return 0;
}