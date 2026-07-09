#include <stdio.h>

long int euclid(long int a, long int b) {

	while(a && b){
		if(a > b){
			a = a%b;
		}
		else if(a < b){
			b = b%a;
		}
		else{
			return a;
		}
	}

	return (!a) ? b : a; 
}

int main(){

	long int a, b;
	int n,i = 0;

	FILE* input = fopen("euclid2.in","r");
	FILE* output = fopen("euclid2.out","w");
	fscanf(input,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(input,"%ld %ld",&a,&b);
		fprintf(output,"%ld\n",euclid(a,b));
	}	

	return 0;
}