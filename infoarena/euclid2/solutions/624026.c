#include <stdio.h>

int main()
{
	unsigned long a,b,r,nr,i;
	FILE *F;
	FILE *FF;
	F=fopen("C:\\Users\\Roland\\Desktop\\cmmdc Euclid\\euclid2.in","r");
	FF=fopen("C:\\Users\\Roland\\Desktop\\cmmdc Euclid\\euclid2.out","w");
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
