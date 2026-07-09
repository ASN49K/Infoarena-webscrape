#include <stdio.h>

int cmmdc(int a, int b){

	if((!a) || (!b)) return a + b;
	if(a > b) return cmmdc(a % b,b);
	return cmmdc(a,b % a);
}

int main(){

	FILE *fi = fopen("cmmdc.in","r");
	FILE *fo = fopen("cmmdc.out","w");
	int a,b,T,i,r;

	fscanf(fi,"%d",&T);

	for(i = 0; i < T; ++i){

		fscanf(fi,"%d%d\n",&a,&b);

		r = cmmdc(a,b);
		
		if(r == 1){
			fprintf(fo,"%d\n",0);
		}else{
			fprintf(fo, "%d\n",r);
		}
	}
	return 0;
}