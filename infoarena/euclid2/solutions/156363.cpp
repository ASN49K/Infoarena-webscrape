#include <stdio.h>


int a, b;

inline int gcd(int a, int b)

{
	if (b == 0) return a;
	return gcd(b, a % b);
}


void read()

{
	scanf("%d %d ", &a, &b);
}


void solve()

{
	
}


void write()

{
	printf("%d\n", gcd(a, b));
}


int main()

{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out","w",stdout);

	int T;
	scanf("%d ", &T);

	for (; T>0; --T)
	{
		read();
		solve();
		write();
	}

	return 0;
}

