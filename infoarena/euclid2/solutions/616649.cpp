#include <cstdio>

using namespace std;

int T;

int cmmdc(int a, int b)
{
	int r;
	while(b)
	{
		r = a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.out", "w", stdout);
	scanf("%d", &T);
	int i, a, b;
	for(i=0; i<T; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}
	
	return 0;
}