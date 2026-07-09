#include<stdio.h>
#include<stdlib.h>

FILE *IN, *OUT;

int n;
int a,b;
int i,nr;

int Cmmdc(int A, int B){
	int rest;
	rest=A%B;

	while(rest){
		A=B;
		B=rest;
		rest=A%B;
	}
	return B;

}

void Citire(){
	fscanf(IN,"%d",&n);
	for(i=1;i<=n;i++){
		fscanf(IN,"%d%d",&a,&b);
		nr=Cmmdc(a,b);
		fprintf(OUT,"%d\n",nr);
	}
}


int main(){
	OUT=fopen("euclid2.out","wt");
	IN=fopen("euclid2.in","rt");

	Citire();


	return 0;
}