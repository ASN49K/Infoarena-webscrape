#include <stdio.h>
#include <assert.h>

int gcd(int a, int b){
	if (!b)
		return a;

	if (a > b)
		return gcd(a - b, b);

	return gcd(a, b - a);
}

int main(){
	FILE *fin = fopen("./euclid2.in", "r"),
		 *fout = fopen("./euclid2.out", "w+");
	assert(fin && fout);

	int T;
	if (fscanf(fin, "%d\n", &T) != 1)
		fputs("Error on read T\n", stderr);

	while (T){
		int a, b;

		fscanf(fin, "%d %d\n", &a, &b);

		fprintf(fout, "%d\n", gcd(a, b));

		--T;
	}

	return 0;
}
