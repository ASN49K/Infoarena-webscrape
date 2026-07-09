#include <iostream>
#include <stdio.h>

using namespace std;

int cmmdc(int a, int b)
{
  if (a == 0)
    return b;

  if (b == 0)
    return a;

  if (a > b)
    return cmmdc(a % b, b);

  return cmmdc(a, b % a);
}

int main (void)
{
  FILE *f = fopen("euclid2.in","rt");
  FILE *g = fopen("euclid2.out","wt");

  if (!f || !g)
  {
    cerr << "Error" << endl;
    return 1;
  }

  int n;

  fscanf(f, "%d", &n);
  int a,b;

  for (int i = 0 ; i < n ; i ++)
  {
    fscanf(f, "%d %d", &a, &b);
    fprintf(g, "%d\n", cmmdc(a,b));
  }

  fclose(f);
  fclose(g);

  return 0;
}