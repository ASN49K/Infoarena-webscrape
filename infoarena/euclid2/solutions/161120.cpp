#include<stdio.h>

long cmmdc(long a, long b)
 {  long r;
    r=a%b;
    while (r)
     { a=b;
       b=r;
       r=a%b;}
    return b;
    }

int main ()
 { FILE*f=fopen("euclid2.in","r");
   FILE*g=fopen("euclid2.out","w");
   long a,b,t,i;
   fscanf(f,"%ld",&t);
   for (i=1;i<=t;i++)
     { fscanf(f,"%ld%ld",&a,&b);
       fprintf(g,"%ld\n",cmmdc(a,b));
       }
   fcloseall();
   return 0;
   }                     