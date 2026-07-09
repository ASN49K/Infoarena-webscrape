#include <stdio.h>
 
int cmmdc(int a, int b);

int main()
{
    int a, b, t, i;
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

int cmmdc(int a, int b)
{
	if (a==b)
		return a;
	if (a>b) return cmmdc(a-b,b);
	return cmmdc(a,b-a);
}
