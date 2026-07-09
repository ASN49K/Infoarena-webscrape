#include <stdio.h>
#define IN "euclid2.in"
#define OUT "euclid2.out"

FILE * fin=fopen(IN,"r");
FILE * fout=fopen(OUT,"w");

int euclid(int a, int b)
{
	if(b==0)
		return a;
	else
		return euclid(b,a%b);
}

int main()
{
	int x,y,t,i;
	
	fscanf(fin,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fscanf(fin,"%d%d",&x,&y);
		fprintf(fout,"%d\n",euclid(x,y));
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
