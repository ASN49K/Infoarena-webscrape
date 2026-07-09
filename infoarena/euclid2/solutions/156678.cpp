#include <cstdio>
using namespace std;

int euclid( int a, int b, int &x, int &y )
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	int x0, y0, d;
	d = euclid( b, a % b, x0, y0 );
	
	x = y0;
	y = x0 - (a / b) * y0;
	return d;
}

int main()
{
	freopen("euclid3.in", "r", stdin);
	freopen("euclid3.out", "w", stdout);
	int t;
	int a, b, c, d, x, y;
	scanf("%d", &t);
	for (; t; t--)
	{/*
		scanf("%d %d %d", &a, &b, &c);
		d = euclid( a, b, x, y );
		
		if (c % d)
			printf("0 0\n");
		else
			printf("%d %d\n", x * (c / d), y * (c / d));*/
		scanf("%d %d",&a,&b);
		printf("%d\n",euclid(a,b,x,y));
	}

	return 0;
}
