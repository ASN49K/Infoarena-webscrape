#include <stdio.h>

int cdc(int,int);


int main(void)
{
    FILE *f,*g;
    int nr,A,B;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&nr);
    while(nr)
    {
	fscanf(f,"%d %d",&A,&B);
	fprintf(g,"%d\n",cdc(A,B));
	--nr;
    }
    fclose(f);
    fclose(g);
    return 0;
}

int cdc(int a, int b)
{
    if(!b) return a;
    return cdc(b,a%b);
}