#include<stdio.h>
int main()
{
 FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
 long int a,b,t;
 fscanf("%ld",&n)
 for(long int i=1;i<=nr;i++)
 {
   fscanf(f,"%ld %ld",&a,&b);
   while(b)
   {
     t=b;
     b=a%b;
     a=t;
   }
   fprintf(g,"%ld\n",a);
   }
 fcloseall();
 return 0;
}