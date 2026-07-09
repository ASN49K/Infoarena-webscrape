#include <stdio.h>
#define INF "euclid2.in"
#define OUF "euclid2.out"

long cmmdc(long a,long b)
{
   long r;
   while(b>0)
   {
     r=a%b;
     a=b;
     b=r;
   }
   return a;
}

int main()
{
  FILE *in,*out;
  in=fopen(INF,"r");
  out=fopen(OUF,"w");
  long alfa,beta;
  fscanf(in,"%ld%ld",&alfa,&beta);
  if(alfa>beta) fprintf(out,"%ld\n",cmmdc(alfa,beta));
  else fprintf(out,"%ld\n",cmmdc(beta,alfa));

  fclose(in);fclose(out);
  return 0;
}