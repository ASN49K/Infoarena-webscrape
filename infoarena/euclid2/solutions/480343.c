#include <stdio.h>

int
main (int argc, char *argv[])
{
  FILE *fin, *fout;
  int i, a, b, r, t;

  fin  = fopen ("euclid2.in", "rt");
  fout = fopen ("euclid2.out", "wt");

  fscanf (fin, "%d", &t);

  a = 18; b = 45;

  for (i = 0; i < t; i++)
    {
      fscanf (fin, "%d", &a);
      fscanf (fin, "%d", &b);
  
      if (a > b)
	{
	  r = a; 
	  a = b;
	  b = r;
	}
  
      while (b != 0)
	{
	  r = a % b;
	  a = b;
	  b = r;
	}

      fprintf (fout, "%d\n", a);
    }

  return 0;
}
