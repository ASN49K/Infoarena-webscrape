#include <stdio.h>
int main()
{
	FILE *fp = fopen("euclid2.in","r");
	int a,b=0;
	fscanf(fp,"%d", &a);
    fscanf(fp,"%d", &b);
	fclose(fp);
	int rez = euclid(a,b);
	fp = fopen("euclid2.out","w");
	fprintf(fp,"%d",rez);
	fclose(fp);
	return 0;
}


int euclid(int a,int b)
{
	int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
	return a;
}