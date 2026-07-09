#include <stdio.h>
long cmmdc (long a,long b)
{long r;
 while(b)
 {r=a%b;
  a=b;
  b=r;
 }
 return a;
}
int main ()
{FILE *f=fopen("euclid2.in","r");
 FILE *fout=fopen("euclid2.out","w");
 long t,a,b,i;
 fscanf(f,"%ld",&t);
 for  (i=0;i<t;i++)
 {fscanf(f,"%ld%ld",&a,&b); 
  fprintf(fout,"%ld\n",cmmdc(a,b));
 }
 return 0;
}