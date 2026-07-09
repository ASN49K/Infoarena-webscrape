#include <stdio.h>
#include <stdlib.h> 

int getDivisor(int a, int b){
	if(a == b) return a;
	if(a < b){
	 	return getDivisor(a, b - a);
	}
	return getDivisor(a - b, b);
}

int main(){
	FILE *in, *out;
	int a, b, n;

	in = fopen("euclid2.in", "r");
	out = fopen("euclid2.out", "w");
	fscanf(in, "%d", &n);
	for(int i = 0; i < n; i++){
		fscanf(in, "%d", &a);
		fscanf(in, "%d", &b);

		fprintf(out, "%d\n", getDivisor(a, b));
	}

	fclose(in);
	fclose(out);
	return 0;
}