#include <cstdio>

using namespace std;

FILE *f = fopen ("euclid2.in","r");
FILE *g = fopen ("euclid2.out","w");

int T, a, b;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	fscanf (f, "%d", &T);
	while (T--)
	{
		fscanf (f, "%d%d", &a, &b);
		fprintf (g, "%d\n", gcd(a,b) );
	}
	
	fclose(f);
	fclose(g);
	
	return 0;
}
