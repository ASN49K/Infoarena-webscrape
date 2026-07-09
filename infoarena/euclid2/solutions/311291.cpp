#include <stdio.h>

long int n, a, b;

long int euclid(long int, long int);

int main()
{
  long int i;
  FILE *fin=fopen ("euclid2.in", "r");
  FILE *fout=fopen ("euclid2.out", "w");
  fscanf (fin, "%ld\n", &n);
  for (i=0; i<n; i++)
    {
      fscanf (fin, "%ld %ld\n", &a, &b);
      fprintf (fout, "%ld\n", euclid (a,b));
    }
  return 0;
}

long int euclid (long int a, long int b)
{
  long int r;
  while (b)
    {
      r=a%b;
      a=b;
      b=r;
    }
  return a;
}