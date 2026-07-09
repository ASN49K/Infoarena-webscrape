#include <stdio.h>
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
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
		fprintf(g,"%d",euclid(x,y));
	}
	return 0;











}
	
