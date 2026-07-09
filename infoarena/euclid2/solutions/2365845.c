#include <stdio.h>

FILE *f, *g;

int euclid(int a , int b){
	if(!b)
	return a;
	return euclid(b,a%b);
}

int main(){
	int n,a,b;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d\n",euclid(a,b));
	}
}
