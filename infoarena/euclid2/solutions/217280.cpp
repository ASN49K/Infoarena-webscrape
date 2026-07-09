#include <stdio.h>
FILE *f;
long int a,b;
int main(void){
	f=fopen("cmmdc.in","r");
	fscanf(f,"%ld %ld",&a,&b);
	fclose(f);
	f=fopen("cmmdc.out","w");
	long int r,aux;
	if (a<b){
		aux=a;
		a=b;
		b=aux;
	}
	else {}
	
	while (b != 0){
		r=a%b;
		a=b;
		b=r;
	}
	
	fprintf(f,"%ld",a);
	
	fclose(f);
}
