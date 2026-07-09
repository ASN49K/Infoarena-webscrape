#include<stdio.h>

int dcom(int a,int b)
{
	if(a==b) return a;
	else if(a<b) return dcom(a,b-a);
	        else return dcom(a-b,b);
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