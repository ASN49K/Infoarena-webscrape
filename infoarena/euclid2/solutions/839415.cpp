#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int n, i, a, b, c;
	FILE* fh = fopen("euclid2.in", "r");
	FILE* fh2 = fopen("euclid2.out", "w");
	
	fscanf(fh, "%d", &n);
	for (i = 0; i<n; i++)
	{
		fscanf(fh, "%d %d", &a, &b);
		while (b)
		{
			c = a % b;
			a = b;
			b = c;
		}
		fprintf(fh2, "%d\n", a);
	}
	
	fclose(fh); fclose(fh2);
}
