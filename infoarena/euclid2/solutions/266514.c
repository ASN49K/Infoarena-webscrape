#include <stdio.h>
#include <stdlib.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

int euclid(int a, int b)
{
   int c;
   while (b)
	{
      c = a % b;
     a = b;
     b = c;
  }
 return a;
}

int nr;
int x,y;
int main()
{
	int i;
	fscanf(f,"%d",&nr);
	for(i=1; i<=nr; i++)
	{
		fscanf(f,"%d %d",&x,&y);
		fprintf(g,"%d\n",euclid(x,y));
	}
	fclose(f);
	fclose(g);
	return 0;
}
