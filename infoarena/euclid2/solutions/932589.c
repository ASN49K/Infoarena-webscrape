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
	int nrLinii = 0, aux1 = 0, aux2 = 0;
	FILE *f, *g;	

	f = fopen ("date.in", "r");
	g = fopen ("date.out", "w");

	fscanf(f, "%i", &nrLinii);

	while (nrLinii-- > 0)
	{
		fscanf(f, "%i %i", &aux1, &aux2);
		if (aux1 > aux2) fprintf (g, "%i\n", cmmdc(aux1, aux2));
		else		 fprintf (g, "%i\n", cmmdc(aux2, aux1));
	}
	
	fclose (f);
	fclose (g);

	return 0;
}
