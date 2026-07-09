#include <stdio.h>
 
long int cmmdc(long int a, long int b);

int main()
{
    long int a, b;
    long int i, t;
    FILE* fin = fopen("euclid2.in","r");
    FILE* fout = fopen("euclid2.out","w");
    fscanf(fin, "%d", &t);
    for(i=0; i<t; i++)
    {
    	fscanf(fin, "%d", &a);
    	fscanf(fin, "%d", &b);
    	fprintf(fout, "%d\n", cmmdc(a,b));
	}
    fclose(fin);
    fclose(fout);
    return 0;
}

long int cmmdc(long int a, long int b)
{
	if (a==b)
		return a;
	if (a>b) return cmmdc(a-b,b);
	return cmmdc(a,b-a);
}
