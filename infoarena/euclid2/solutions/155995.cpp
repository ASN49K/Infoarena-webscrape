#include <stdio.h>


int cmmdc(int,int);
int main()
{
	int x, y, r, T;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	for(scanf("%d\n", &T); T; T--)
	{
		scanf("%d %d\n", &x, &y);
		printf("%d\n", cmmdc(x,y));
	}


	return 0;
}

int cmmdc(int x, int y)
{
        int r;
	while (y)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}