#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y){
    if (y == 0)
       return x; 
    else
       return gcd(y, x % y);
}

int t;
int a,b;


void main(){
	
	
	FILE *f, *g;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");

	fscanf(f,"%d",&t);
	
	for (int i = 0;i<t;i++){
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d\n",gcd(a,b));	
	}
	fclose(f);
	fclose(g);


}