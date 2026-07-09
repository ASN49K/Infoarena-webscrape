#include <stdio.h>
//#include <fstream.h>
#include <stdlib.h>


int euclid (int a, int b)
{
	int r;
	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main()
{
	int x,y,rez,nr,i;
	//FILE *f=fopen("euclid2.in", "r");
	//FILE *g=fopen("euclid2.out", "r+");
	    freopen("euclid2.in", "r", stdin);
	
    freopen("euclid2.out", "w", stdout);
	//nr=fscanf(f,"%d", &nr);
	scanf("%d", &nr);
	for (i=0;i<nr;i++)
	{
		scanf("%d%d", &x,&y);
		//x=fscanf(f,"%d", &x);
		//printf("%d ", x);
		//y=fscanf(f,"%d",&y);
		//printf("%d\n",y);
		//fgets(&x,sizeof(int), f);
		//fgets(&y,sizeof(int),f);
		rez=euclid(x,y);
		//fwrite(&rez,1,sizeof(int),g);
		//fprintf(g, "%d\n",rez );
		printf("%d\n",rez);
	}

	//fclose(f);
	//fclose(g);

		
	
	return 0;
}