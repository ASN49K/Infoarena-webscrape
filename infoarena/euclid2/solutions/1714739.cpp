#include <stdio.h>

int main()
{
  FILE *fin, *fout;
  fin = fopen("euclid2.in", "r");
  long int n = 0, a, b;
  fscanf(fin,"%ld", &n);
  fout = fopen("euclid2.out", "w");
  for (int i = 0; i < n; i++ ) 
  {
    fscanf(fin, "%ld %ld", &a, &b);
    //fprintf(fout, "%ld %ld\n", a, b);
    long int cmmdc, r, c;
    do
    {
      //c = a / b;
      r = a % b;
      a = b;
      b = r;
    } while (r);
    cmmdc = a;
    fprintf(fout, "%ld\n", cmmdc);
  } 

  fclose(fin);
  fclose(fout);
  return 0;
}