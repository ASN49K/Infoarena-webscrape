#include <stdio.h>

int gcd(int a, int b){

	if(!b) return a;
	return gcd(b, a % b);

}

int main(){

	FILE *finput, *foutput;

	finput = fopen("euclid2.in", "r")
	foutput = fopen("euclid2.out", "w");

	int T;
	long long int a, b;

	for(fscanf(finput, "%d", &T); T > 0; T--){
		fscanf(finput, "%lld %lld", &a, &b);
		fprintf(foutput, "%lld", gcd(a, b));
	}

	return 0;


}