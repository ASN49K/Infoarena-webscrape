#include <stdio.h>
int main()
{ long a,b;
  FILE *f=fopen("euclid2.in","rt");
  FILE *g=fopen("euclid2.out","wt");
  fscanf(f,"%ld %ld",&a,&b);
  long r;
  while (r)
	{ r=a%b;
	  a=b;
	  b=r;
	}
  fprintf(g,"%ld",a);
  fclose(f);
  fclose(g);
  return 0;
}
