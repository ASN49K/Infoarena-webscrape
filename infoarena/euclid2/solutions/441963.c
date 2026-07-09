#include <stdio.h>
int main (){
	int aux,m,n,x,i;
	FILE *f,*g;
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%d",&x);
for(i=0;i<x;i++)
	{
		fscanf(f,"%d",&n);
		fscanf(f,"%d",&m);
			while (m!=0)
			{
			   aux = m;
			   m = n%m;
			   n = aux;
			}
	fprintf(g,"%d ",n);
}
fclose(f);
fclose(g);
return 0;
}


