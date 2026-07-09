#include<stdio.h>
#include<stdlib.h>

long int euclid(long int a,long int b)
   {
    if (!b) return a;
    return euclid(b,a%b);
   }

int main()
  {
   FILE *f=fopen("euclid2.in","rt");
   FILE *g=fopen("euclid2.out","wt");
   
   long int a,b,t;
   fscanf(f,"%li",&t);
   for(;t;--t)
     {
   fscanf(f,"%li%li",&a,&b);
   fprintf(g,"%li\n",euclid(a,b)); 
     }
   fclose(f);
   fclose(g);
   return 0;
  }
