#include<iostream.h>
#include<stdio.h>
int main ()
{unsigned long t, a, b,i,r;
FILE *f,*g;
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%ld",&t);
for(i=1;i<=t;i++)
  {
  fscanf(f,"%ld%ld",&a,&b);
   do
    {
     r=a%b;
     a=b;
     b=r;
    }
   while(r!=0);
   fprintf(g,"%ld\n",a);
  }
fclose(f);
fclose(g);
return 0;
}