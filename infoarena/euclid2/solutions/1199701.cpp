#include<stdio.h>
#include<stdlib.h>
using namespace std;
int cmmdc(int a,int b)
{
	while (a != b)
		if (a > b)
			a = a - b;
		else
			b = b - a;
	return a;
}
int main()
{
	FILE* f;
	FILE* f2;
	f2 = fopen("euclid2.out", "w");
	f = fopen("euclid2.in", "r");
	int n,i;
	n = fgetc(f);
	for (i = 1; i <= n; i++)
	{
		int a, b;
		a = fgetc(f);
		b = fgetc(f);
		fprintf(f2,"%d\n",cmmdc(a,b));
	}
	return 0;
}