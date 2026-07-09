#include <stdio.h>
#include <stdlib.h> 

/*
Scaderi repetate
int getDivisor(int a, int b){
	if(a == b) return a;
	if(a < b){
	 	return getDivisor(a, b - a);
	}
	return getDivisor(a - b, b);
}
*/

int getDivisor(int a, int b){
	if(b == 0) return a;
	return getDivisor(b, a % b);
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