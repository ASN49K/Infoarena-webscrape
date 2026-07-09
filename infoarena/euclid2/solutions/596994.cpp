#include <stdio.h>

int cmmdc(int a, int b) 
{
	if (!b) return a;
	else return cmmdc(b, a%b);
}

int main () {
	FILE *f,*g;
	int n,x,y;
	f=fopen("euclid2.in", "r");
	g=fopen("euclid2.out", "w");
	fscanf(f, "%d", &n);
	for (; n>=1; n--) 
	{
		fscanf(f, "%d %d", &x,&y);
		fprintf(g, "%d\n", cmmdc(x,y));
	}
	
	
	fclose(f); fclose(g); return 0;
}