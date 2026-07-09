#include <stdio.h>

#define INPUT	"euclid2.in"
#define OUTPUT	"euclid2.out"

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main(void)
{
	FILE *f_in, *f_out;
	int count, i, a, b, res;
	
	f_in  = fopen(INPUT, "r");
	f_out = fopen(OUTPUT, "w");

	fscanf(f_in, "%d\n", &count);
	
	for (i = 0; i < count; i++) {
		fscanf(f_in, "%d %d\n", &a, &b);
		res = gcd(a,b);
		fprintf(f_out, "%d\n", res);
	}
	
	fclose(f_in);
	fclose(f_out);
	
	return 0;
}
