#include <stdio.h>
int main(){
	FILE *f,*g;
	long t,a,b;
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	fscanf(f,"%ld",&t);
	for(long i=1;i<=t;i++){
		fscanf(f,"%ld%ld",&a,&b);
			long r=0;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
   fprintf(g,"%ld\n",a);
	}
	fclose(f);
	fclose(g);
	return 0;
}
