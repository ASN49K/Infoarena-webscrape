#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    if (b == 0)
       return a; 
    else
       return gcd(b, a % b);
}

void main(){
	int t;

	FILE *f, *g;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");

	fscanf(f,"%d",&t);
	int a,b;
	for (int i = 0;i<t;i++){
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d\n",gcd(a,b));	
	}
	fclose(f);
	fclose(g);


}