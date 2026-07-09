#include<stdio.h>

int dcom(int a,int b)
{
	if(b==0) return a;
	return dcom(b,a%b);
}

int main()
{
	FILE *f,*g;
	int a,b,t,i;
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	fscanf(f,"%d",&t);
	for(i=0;i<t;i++)
	{
		fscanf(f,"%d%d",&a,&b);
		fprintf(g,"%d\n",dcom(a,b));
	
	}
	fclose(g);

	return 0;
}