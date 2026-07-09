#include<stdio.h>
FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");
int main()
 {
 int t,r,a,b;
 fscanf(f,"%d",&t);
 while(t--)
  {
  fscanf(f,"%d %d\n",&a,&b);
  r=a%b;
  while(r)
   {
   a=b;
   b=r;
   r=a%b;
   }
  fprintf(g,"%d\n",b);
  }
 return 0;
 }
