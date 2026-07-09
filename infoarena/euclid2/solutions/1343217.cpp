#include<stdio.h>
long long a,b,c; long t;
int main(){
	FILE*f=fopen("euclid2.in","r");
	FILE*g=fopen("euclid2.out","w");
	fscanf(f,"%ld",&t);
	while(t--){
		fscanf(f,"%lld %lld",&a,&b);
		while(b){
			c=a%b;
			a=b;
			b=c;
		}
		fprintf(g,"%lld\n",a);
	}
	fclose(f);
	fclose(g);
	return 0;
}