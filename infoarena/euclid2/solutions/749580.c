#include<stdio.h>
#include<stdlib.h>

FILE *IN, *OUT;

int n;
int a[1000],b[1000];
int i;

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
	for(i=1;i<=n;i++)
		fscanf(IN,"%d%d",&a[i],&b[i]);

}
void Rezolvare(){
	int nr;
	for(i=1;i<=n;i++){
		nr=Cmmdc(a[i],b[i]);
		fprintf(OUT,"%d\n", nr);
	}

}

int main(){
	OUT=fopen("euclid2.out","wt");
	IN=fopen("euclid2.in","rt");

	Citire();

	Rezolvare();
	return 0;
}