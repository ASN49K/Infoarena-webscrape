#include <stdio.h>
int t, a, b;
int euclid(int x, int y)
{
	if (x>y)
	{
		int p;
		p =x; x= y; y=p;
	}
	if (x == 0)
		return y;
	return euclid(x,y%x);
}
		
int main()
{
	freopen("euclid2.in", "r",stdin);
	freopen("eculid2.out","w",stdout);
	scanf("%d", &t);
	for (; t>0; --t)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", euclid(a,b));
	}
	return 0;
}