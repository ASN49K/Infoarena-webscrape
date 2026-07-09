#include<stdio.h>
#include<stdlib.h>

int divisor (int a, int b){

	if (!b) return a;
	else return divisor(b,a%b);
}

int main(){
	int a,b,T,i;
	FILE *in ,*out;

	in = fopen("euclid2.in","r");
	out = fopen("euclid2.out","w");
	fscanf(in,"%d",&T);
	while (T--) {
		fscanf(in,"%d %d",&a,&b);
		fprintf(out,"%d\n",divisor(a,b));
		}
return 0;
}
