#include<stdio.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
using namespace std;
int main(){
	int a,b,r,T;
	for(fscanf(f,"%d",&T);T;--T){
	fscanf(f,"%d%d",&a,&b);
	r=b;
	while(r!=0){
		r=a%b;
		a=b;
		b=r;
	}
	fprintf(g,"%d\n",a);
	}
return 0;
}
