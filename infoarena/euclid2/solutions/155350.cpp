#include <cstdio>

int n;
int a, b;


void read()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &n);
}

void readtest()
{
	scanf("%d%d", &a, &b);
}

int ecl(int a, int b)
{
	if(a % b == 0)
		return b;
	else
		return ecl(b%a, a);
}

int main()
{
	read();
	
	while(n)
	{
		readtest();
		printf("%d\n", ecl(a, b));
		n--;
	}
	return 0;
}
