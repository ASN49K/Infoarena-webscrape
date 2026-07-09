#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	long a, b; int T;
	f = fopen("euclid2.in", "r");
	g = fopen("euclid2.out", "w");
	fscanf(f, "%d", &T);
	for (int i=1; i<=T; i++)
	{
		fscanf(f, "%d %d", &a, &b);
		while(b != 0)
		{
			int r = a % b;
			a = b;
			b = r;
		}
		fprintf(g, "%d\n", a);
	}
	fclose(f); fclose(g);
	return 0;
}