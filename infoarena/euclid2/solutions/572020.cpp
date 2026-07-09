#include<stdio.h>

int main()
{
	FILE *f,*g;
	int a,b,t,i;
	f=fopen("adunare.in","r");
	g=fopen("adunare.out","w");
	fscanf(f,"%d",&t);
	for(i=0;i<t;i++)
	{
		fscanf(f,"%d%d",&a,&b);
		while(a!=b)
		{
			if(a>b) a=a-b;
			else b=b-a;

		}
		fprintf(g,"%d\n",a);
	
	}
	

	fclose(g);

	return 0;
}