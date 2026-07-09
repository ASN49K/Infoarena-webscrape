#include <stdio.h>

int main()
{
	int t, a, b;
	FILE *in, *out;

	in = fopen("euclid2.in", "r");
	out = fopen("euclid2.out", "w");

	fscanf(in, "%d", &t);

	while(t-- > 0){
		fscanf(in, "%d%d\n", &a,&b);
		while(a%b != 0){
			int aux = b;
			b = a%b;
			a = aux;
		}
		fprintf(out, "%d\n", b);
	}

	fclose(in);
	fclose(out);

	return 0;
}