#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int cmmdc(int a, int b)
{
	if (!b) return a;
	else return cmmdc (b, a%b);
}

int main()
{
	int nrLinii, aux1, aux2;
	FILE *f, *g;	

	f = fopen ("euclid2.in", "r");
	g = fopen ("euclid2.out", "w");

	fscanf(f, "%i", &nrLinii);

	while (nrLinii-- > 0)
	{
		fscanf (f, "%i %i", &aux1, &aux2);
		fprintf (g, "%i\n", cmmdc(aux1, aux2));
	}
	
	fclose (f);
	fclose (g);

	return 0;
}
