#include<stdio.h>

int euclid (int a, int b)
{
  	if(!b)
  	{
    		return a;
	}
	return euclid(b,a%b);
}

int main ()
{
  FILE *in, *out;
  in=fopen("euclid2.in","r");
  out=fopen("euclid2.out","w");
  int a,b,T;
  fscanf(in,"%d",&T);
  while (T)
  {
    fscanf(in,"%d%d",&a,&b);
    fprintf(out,"%d\n",euclid(a,b));
    --T;
  }
  fclose(in);
  fclose(out);
  return 0;
}
