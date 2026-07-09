#include <stdio.h>
int main()
{
	FILE *f = fopen("euclid2.in","r");
	FILE *g = fopen("euclid2.out","w");
	int t,x,y;
	fscanf(f,"%d",&t);
	for(int i=0;i<t;i++)
	{
		fscanf(f,"%d",&x);
		fscanf(f,"%d",&y);
		while(x!=y)
		{
			if(x>y)
				x=x-y;
			else
				y=y-x;
		}
		fprintf(g,"%d",x);
	}
	return 0;











}
	
