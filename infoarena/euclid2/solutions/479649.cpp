#include <iostream>

using namespace std;

int cmmdc (int a, int b)
{
	while (b)
	{
		int aux = a;
		a = b;
		b = aux % b;
	}	
	
	return a;
}

int main()
{
	int T, a, b;
	
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.out", "w", stdout);
	
	scanf ("%d", &T);
	
	while (T--)
	{
		scanf ("%d %d", &a, &b);
		printf ("%d\n", cmmdc(a,b));
	}	
	
	return 0;
}