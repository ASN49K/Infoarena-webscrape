#include<stdio.h>
#include<stdlib.h>

int a,b,c;

int r;

void cmmdc(int a,int b){
	do{
		r=a%b;
		a=b;
		b=r;
	}while(r>0);
	c=a;
}

int main(){
	int T;
	FILE* f= fopen("euclid2.in","rt");
	FILE* g= fopen("euclid2.out","wt");
	fscanf(f,"%d",&T);

	for(int i=0;i<T;i++){
		fscanf(f,"%d %d",&a,&b);
		cmmdc(a,b);	
		fprintf(g,"%d\n",c);
	}

	fclose(g);
	fclose(f);
	return 0;
}