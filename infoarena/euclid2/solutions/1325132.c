/*
	Cmmdc varianta binara.
*/

#include <stdio.h>

FILE *in, *out;
int n;

int cmmdc(int a, int b) {

	if (a == 0 || b == 0)
		return a + b;
	
	if (a % 2 == 0 && b % 2 == 0)
		return 2 * cmmdc(a/2, b/2);
	
	if (a % 2 == 0 && b % 2 == 1)
		return cmmdc(a/2, b);

	if (a % 2 == 1 && b % 2 == 0)
		return cmmdc(a, b/2);

	if (a > b)
		return cmmdc(a-b, b);
	else
		return cmmdc(a, b-a);
}

int main () {
	int i, x, a, b;

	in 	= fopen("euclid2.in", "r");
	out = fopen("euclid2.out", "w");

	fscanf(in, "%d", &n);

	for (i=1; i<=n; i++)
	{
		fscanf(in, "%d", &a);
		fscanf(in, "%d", &b);

		x = cmmdc(a, b);
		fprintf(out, "%d\n", x);
	}


	fclose(out);
	fclose(in);

	return 0;
}