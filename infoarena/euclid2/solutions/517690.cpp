#include<cstdio>

FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");

int a,b,T;

int euclid(int a,int b){
	int r;
	while( b ){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main () {
	fscanf(f,"%d",&T);
	
	while ( T-- ){
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d\n",euclid(a,b));
	}
	
	fclose(f);
	fclose(g);
	
	return 0;
}
