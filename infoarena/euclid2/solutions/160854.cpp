#include <stdio.h>
FILE *f,*g;
long print(long a, long b);
int main()
{
  long i,x,y,n;
  f=fopen("euclid2.in","rt");
  g=fopen("euclid2.out","wt");
  fscanf(f,"%ld\n",&n);
  for (i=1;i<=n;i++)
    {
      fscanf(f,"%ld %ld\n",&x,&y);
      fprintf(g,"%ld\n",print(x,y));
    }
  fclose(f);
  fclose(g);
  return 0;
}

long print(long a, long b)
{
  long r;
  while (b)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}
