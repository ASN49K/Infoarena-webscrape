#include<stdio.h>
#include<stdlib.h>;
FILE *fin,*fout;

int main(){

	long T,a,b,min,d;

	fin = fopen("euclid2.in","r");
	fout = fopen("euclid2.out","w");

	fscanf(fin,"%ld",&T);

	for(int i=0;i<T;i++){
		
		fscanf(fin,"%ld %ld",&a,&b);

		a<b?min=a:min=b;
		//printf("min = %d", min);
		d=1;
		for(int j=2;j<=min;j++){
			
			if(a%j==0 && b%j==0)
				d=j;
			
		}
		
		fprintf(fout,"%ld\n",d);

	}
	

}