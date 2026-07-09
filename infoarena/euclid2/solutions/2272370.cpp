#include<stdio.h>

int a,b,r;

int main(){
	int T;
	FILE* f= fopen("euclid2.in","rt");
	FILE* g= fopen("euclid2.out","wt");
	fscanf(f,"%d",&T);

	for(int i=0;i<T;i++){
		fscanf(f,"%d %d",&a,&b);
		do{
			r=a%b;
			a=b;
			b=r;
		}while(r>0);
	
		fprintf(g,"%d\n",a);
	}

	fclose(g);
	fclose(f);
	return 0;
}