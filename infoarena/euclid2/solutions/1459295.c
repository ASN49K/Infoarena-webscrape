#include <stdio.h>

int cmmdc(int a, int b){

	if((!a) || (!b)) return a + b;
	if(a > b) return cmmdc(a % b,b);
	return cmmdc(a,b % a);
}

int main(){

	FILE *fi = fopen("euclid2.in","r");
	FILE *fo = fopen("euclid2.out","w");
	int a,b,T,i;

	fscanf(fi,"%d",&T);

	for(i = 0; i < T; ++i){
		fscanf(fi,"%d%d\n",&a,&b);		
		fprintf(fo, "%d\n",cmmdc(a,b));
	}
	return 0;
}