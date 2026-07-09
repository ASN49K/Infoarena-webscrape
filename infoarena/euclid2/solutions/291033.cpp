#include<stdio.h>
long n,x,y;
int gcd(int a,int b){
	long r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
} 
int main(){
	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");
	fscanf(f,"%ld",&n);
	for(; n-- ;){
		fscanf(f,"%ld%ld",&x,&y);
		fprintf(g,"%ld\n",gcd(x,y));
	}
	return 0;
}