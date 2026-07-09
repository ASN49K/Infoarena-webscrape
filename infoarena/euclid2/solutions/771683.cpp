#include <iostream>
#include <fstream>
using namespace std;
long cmmdc (long a, long b)
{
	if (!b) return a;
	return cmmdc(b, a%b);
}
int main () {
	long i,x,y;
	FILE *f,*g;
	f=fopen("euclid2.in", "r");
	g=fopen("euclid2.out", "w");
	fscanf(f, "%d", &i);
	for (; i>0; i--)
	{
		fscanf(f, "%d %d", &x,&y);
		fprintf(g, "%d\n", cmmdc(x,y));
	}
	fclose(f);fclose(g);
	return 0;
}