#include "stdio.h"

int Euclid(int a,int b){
	int tmp;
	if(a<b){
		b = a + b;
		a = b - a;
		b = b - a;
	}
	while(b!=0){
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}



int main(){
	int a,b,n;
	int i;
	FILE *f,*g;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");

	fscanf(f,"%d",&n);
	for(i=0;i<n;i++){
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d \n",Euclid(a,b));
	}
	
	
	return 0;
}