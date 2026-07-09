#include <stdio.h>

int main()
{
        int a,b,r,nr,i;
	FILE *F;
	FILE *FF;
	F=fopen("euclid2.in","r");
	FF=fopen("euclid2.out","w");
	fscanf(F,"%d",&nr);
	for(i=1; i<=nr; i++)
	{
		fscanf(F,"%d%d",&a,&b);
		while(b!=0)
	{
		r=a%b;	
		a=b;
		b=r;
	}
		fprintf(FF,"%d\n",a);
	}
	fclose(F);
	fclose(FF);
	
	return 0;
}
