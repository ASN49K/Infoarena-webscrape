#include<cstdio>

int T;

int cmmdc(int a, int b)
{
	if(b == 0) return a;
	return cmmdc(b, a % b);
}

int main()
{
	int i, a, b;
	
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		scanf("%d %d", &a, &b);
		
		int d = cmmdc(a, b);
		printf("%d\n", d);
	}
	
	return 0;
}
