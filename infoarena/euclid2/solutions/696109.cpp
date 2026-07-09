#include<stdio.h>
#include<fstream.h>
int main ()
{
	long a,b,t,r,i;
	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");
	fscanf(f,"%d",&t);
	for (i=1;i<=t;i++) {
		fscanf(f,"%d %d",&a,&b);
		while (a%b!=0) {
			r=a%b;
			a=b;
			b=r;}
		fprintf(g,"%d\n",b);
	}
	fclose(f);
	fclose(g);
	return 0;
}
