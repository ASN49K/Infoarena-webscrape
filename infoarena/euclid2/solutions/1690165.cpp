#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
FILE *in, *out;

void solve();
int cmmdc(int a, int b)
{
	int rest;
	if (b > a)
		std::swap(a, b);
	rest = a%b;
	if (rest == 0)
		return b;
	while (rest)
	{
		rest = a%b;
		a = b;
		b = rest;
	}
	return a;
};
void main()
{
	in = fopen("euclid2.in","r");
	out = fopen("euclid2.out","w");
	solve();
}
void solve()
{
	int n,x,y;
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(in,"%d%d",&x,&y);
		fprintf(out,"%d \n", cmmdc(x, y));
	}
}