#include<iostream>
#include<fstream>

using namespace std;

int n, a, b;
int cmmdc(int a, int b)
{
	if(!b) return a;
	else
		return cmmdc(b,a%b);
}

int main()
{
	int i;
	FILE *f=fopen("euclid2.in", "r");
	FILE *g=fopen("euclid2.out", "w");
	
	fscanf(f, "%d", &n);
	
	for(i=0;i<n;i++)
	{
		fscanf(f, "%d %d", &a, &b);
		if(a<b)
			fprintf (g, "%d \n", cmmdc(b,a));
		else
			fprintf(g, "%d \n", cmmdc(a,b));
	}
	
	fclose(f);
	fclose(g);
	return 0;
}

