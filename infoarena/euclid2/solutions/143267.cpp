#include<stdio.h>
int main()
  {
  int a,b;
  FILE*f=fopen("euclid2.in","r");
  FILE*g=fopen("euclid2.out","w");
  int r;
  fscanf(f,"%d %d",&a,&b);
  r=a%b;
  while(r)
   {
   a=b;
   b=r;
   r=a%b;
   }
  fprintf(g,"%d\n",b);
  return 0;
  }