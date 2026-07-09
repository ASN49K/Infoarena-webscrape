#include <stdio.h>
//#include <time.h>
 
int cmmdc(int a, int b);

int main()
{
    int a, b;
    int i, t;
    //clock_t begin, end;
    //double time_spent;
    int x=1;
    int j,k;
    //begin = clock();
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
    //end = clock();
    //time_spent = (double)(end - begin);
    //printf("%f", time_spent / CLOCKS_PER_SEC);
    return 0;
}

int cmmdc(int a, int b)
{
	if ((a==1) || (a==b)) return a;
	if (b==1) return b;
	if (a>b) return cmmdc(a-b,b);
	return cmmdc(a,b-a);
}
