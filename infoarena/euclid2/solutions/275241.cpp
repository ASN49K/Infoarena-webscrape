#include<stdio.h>
long cmmdc(long a,long b)
{
   long t;
   while(b!=0)
   {
      t=b;
      b=a%b;
      a=t;
   }
   return a;
}
int main()
{
   FILE *fi,*fo;
   fi=fopen("euclid2.in","r");
   fo=fopen("euclid2.out","w");
   long n,a,b;
   fscanf(fi,"%ld",&n);
   for(;n--;)
   {
      fscanf(fi,"%ld %ld",&a,&b);
      fprintf(fo,"%ld\n",cmmdc(a,b));
   }
   return 0;
}