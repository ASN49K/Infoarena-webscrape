#include <stdio.h>
#include <stdlib.h>

int CMMDC (int a, int b)
{
	if (b == 0) return a;
	return CMMDC (b, a % b);
}

int main (int argc, char const *argv[])
{
	FILE *Fin, *Fout;
	int lines, A, B;

	Fin = fopen ("euclid2.in", "r");
    Fout = fopen ("euclid2.out", "w");
 	
 	if (Fin ==  NULL)
 	{
    	printf ("[Eroare]: Fisierul nu exista:  %s\n", argv[1]);
    	exit (1);
  	}
    
    fscanf (Fin, "%d", &lines);
    while (lines)
    {
        fscanf (Fin, "%d %d", &A, &B);
        fprintf(Fout, "%d\n", CMMDC (A, B));
    }   
	return 0;
}