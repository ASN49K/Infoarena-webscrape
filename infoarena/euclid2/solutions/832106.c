#include <stdio.h>


int cmmdc(int a, int b)
{
	int r = b;
	
	while( r != 0 ){
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main(int argc, char* argv[])
{
	int n;
	FILE *fin,*fout;
	
	fin = fopen("euclid2.in","r");
	fout = fopen("euclid2.out","w");
	
	fscanf(fin,"%d",&n);
	int i;
	for(i=0;i<n;i++){
		int a,b;
		fscanf(fin,"%d %d",&a,&b);
		fprintf(fout,"%d\n", cmmdc(a,b));
	}
	
	
	fclose(fin);
	fclose(fout);
	return 0;
}
