#include <stdio.h>
int euclid(int a, int b)
{
    while (a!=b) {
        if(a>b)
		a=a-b;
	else
		b=b-a;
    }
    return a;
}
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
		fprintf(g,"%d\n",euclid(x,y));
	}
	return 0;











}
	
