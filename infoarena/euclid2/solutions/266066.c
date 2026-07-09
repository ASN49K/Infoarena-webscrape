#include <stdio.h>

int main()
{
	FILE *f1 = fopen("euclid2.in", "r");
	FILE *f2 = fopen("euclid2.out", "w");
	int n, a, b, c;
	fscanf(f1, "%d", &n);
	while(n){
		fscanf(f1, "%d", &a);
		fscanf(f1, "%d", &b);
		while(b){
			c = a%b;
			a = b;
			b = c;
		}
		n--;
		fprintf(f2, "%d\n", a);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}