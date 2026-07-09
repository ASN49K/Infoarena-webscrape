#include<stdio.h>
int T;
long long int a, b, r;
long long int cmmdc(long long int a, long long int b)
{
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	FILE *f, *g;
	f = fopen("euclid2.in", "r");
	g = fopen("euclid2.out", "w");
	fscanf(f, "%d", &T);
	while(T)
	{
		fscanf(f, "%lld %lld", &a, &b);
		fprintf(g, "%lld\n", cmmdc(a, b));
		T--;
	}
	fclose(f);
	fclose(g);
	return 0;
}


