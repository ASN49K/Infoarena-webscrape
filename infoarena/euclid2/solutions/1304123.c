#include <stdio.h>

int main(){

	long int n,a,b,r,aux;

	FILE *in = fopen("euclid2.in","r");
	FILE *out = fopen("euclid2.out","w");

	fscanf(in,"%ld",&n);
	
	while(n>0){
		fscanf(in,"%ld %ld",&a,&b);
		r=b;		
		while(b!=0){
			if(a<b){
				aux=a;
				a=b;
				b=aux;			
			}
			aux=a;	
			a=b;
			b=aux%b;		
		}
	
		fprintf(out,"%ld\n",a);
		n--;
	}

//	fprintf(out,"%ld",n);

	fclose(out);
}

