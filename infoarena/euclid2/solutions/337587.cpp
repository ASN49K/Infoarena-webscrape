#include <stdio.h>
long cmmdc(long a,long b){
	long r=0;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	FILE *f,*g;
	long t,a,b;
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	fscanf(f,"%ld",&t);
	for(long i=1;i<=t;i++){
		fscanf(f,"%ld%ld",&a,&b);
		fprintf(g,"%ld\n",cmmdc(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}
