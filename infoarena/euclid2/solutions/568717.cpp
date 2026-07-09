#include <stdio.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int a,b,t;

int mdiv(int x,int y){
	if(!y)
		return x;
	else 
		return mdiv(y,x%y);
}

int main(void){
	register int i;
	
	fscanf(f,"%d",&t);
	for(;t>0;t--){
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d\n",mdiv(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}