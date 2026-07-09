#include <stdio.h>
int main()
{
	int r,a,b;
	FILE *f1,*f2;

	f1=fopen("euclid2.in","r");
	f2=fopen("euclid2.out","w");
	fscanf(f1,"%d%d",&a,&b);

	while (a%b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	if (b!=1) fprintf(f2,"%d\n",b);
	else fprintf(f2,"0\n");

	fclose(f1);
	fclose(f2);
	return 0;
}
