/*
5. Cmmdc varianta binara.
*/

/*
Varianta normala (Euclid):
(a, b) -> (b, r) -> (r, r1) -> (r1, r2) -> .. (rn, 0) => rn = cmmdc

Varianta binara:

*/


#include <stdio.h>

FILE *in, *out;
int n, a, b, cmmdc;

int main ()
{
	int i, x, y, r;

	in 	= fopen("euclid2.in", "r");
	out = fopen("euclid2.out", "w");


	fscanf(in, "%d", &n);

	for (i=1; i<=n; i++)
	{
		fscanf(in, "%d", &a);
		fscanf(in, "%d", &b);

		x = a;
		y = b;
		while (y > 0)
		{
			r = x % y;
			x = y;
			y = r;
		}
		fprintf(out, "%d\n", x);
	}

	fclose(out);
	fclose(in);

	return 0;
}