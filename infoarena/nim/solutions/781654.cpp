#include<stdio.h>

using namespace std;

int t, n, x, i;
long long int s;

int main()
{
	FILE *f = fopen("nim.in", "r");
	
	FILE *g = fopen("nim.out", "w");
	
	fscanf(f, "%d", &t);
	
	for( ; t; --t)
	{
		fscanf(f, "%d", &n), s = 0;
		for(i = 0; i < n; ++i)
			fscanf(f, "%d", &x), s ^= x;
		
		if(s)
			fprintf(g, "DA\n");
		else
			fprintf(g, "NU\n");
	}
	
	fclose(f);
	
	fclose(g);
	
	return 0;
}


