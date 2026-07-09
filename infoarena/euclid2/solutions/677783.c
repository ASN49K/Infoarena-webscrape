#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b){
	if(! b)
		return a;
	return cmmdc(b, a%b);	
}

int main(int argc, char** argv){
	int a,b,count,i;
	
	FILE *fr = fopen("euclid2.in", "r");
	fscanf(fr, "%d", &count);
	FILE *fw = fopen("euclid2.out", "w");	
	
	for(i = 0; i < count; i++){
		fscanf(fr, "%d", &a);
		fscanf(fr, "%d", &b);
		int res = cmmdc(a,b);
		fprintf(fw, "%d\n", res);
	}
	
	fclose(fr);
	fclose(fw);
}
