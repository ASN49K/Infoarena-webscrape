#include "stdio.h"

int Euclid(int a,int b){
	while(b!=0){
		if(a>b){
			a = a-b;
		}
		else{
			b = b-a;
		}
	}
	return a;
}



int main(){
	int a[10000],b[10000],n;
	int i;
	FILE *f,*g;
	f = fopen("cmmdc.in","r");
	g = fopen("cmmdc.out","w");

	fscanf(f,"%d",&n);
	for(i=0;i<n;i++){
		fscanf(f,"%d %d",&a[i],&b[i]);
	}
	
	for(i=0;i<n;i++){
		fprintf(g,"%d \n",Euclid(a[i],b[i]));
	}
	
	return 0;
}