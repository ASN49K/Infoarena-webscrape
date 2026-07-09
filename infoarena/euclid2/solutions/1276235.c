#include <stdio.h>
#include <stdlib.h>
FILE *f,*g;
int main()
{
  f=fopen("euclid2.in","r");
  g=fopen("euclid2.out","w");
  int a,b,n,r;
  fscanf(f,"%d",&n);
  while(n)
 {fscanf(f,"%d",&a);
 fscanf(f,"%d",&b);
r=a%b;
  while(r)
  {
     a=b;
     b=r;
     r=a%b;
   }

fprintf(g,"%d\n",b);
n--;
 }

  return 0;
}
