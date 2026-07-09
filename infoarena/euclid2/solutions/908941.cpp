#include "stdio.h"
#include "stdlib.h"

void euclid(long a, long b, long *rez)
{
	long aux;

	if (a > b){
		aux = a;
		a = b;
		b = aux;
	}

	while (a%b != 0){
			aux = b;
			b = a % b;
			a = aux;
	}

	*rez = b;
}

int main()
{
	FILE *f = fopen("euclid2.in","r");
	FILE *g = fopen("euclid2.out","w");
	int n,i;
	fscanf(f,"%d",&n);
	
	for (i=0;i<n;i++){
		long x, y, rez;
		fscanf(f,"%ld %ld", &x,&y);
		euclid(x,y,&rez);
		fprintf(g,"%ld\n",rez);
	}
	return 0;
}