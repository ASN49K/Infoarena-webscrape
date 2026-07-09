#include<stdio.h>


int gcd(a,b)
{ int t=0;
	
		if(a<b){
			
			t=a;
			a=b;
			b=t;
			
			
		}
		

	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}
	
	return a;
}

int main(){
char input_filename[] = "euclid2.in";

FILE *in = fopen(input_filename,"rt");

if(in==NULL){
	
	fprintf(stderr, "ERROR");
	return -1;
		
}

char output_filename[]="euclid2.out";

FILE *out=fopen(output_filename,"wt");

int n;
int aux;
fscanf(in, "%d", &n);
int i=1;

for(i=1;i<=n;i++){
int a,b;
fscanf(in,"%d",&a);
fscanf(in,"%d",&b);
aux=gcd(a,b);
fprintf(out,"%d",aux);
fprintf(out,"\n");
}
return 0;
}
