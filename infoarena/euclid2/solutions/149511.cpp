#include <stdio.h>

 long a,b,x;

 int citire()
  {FILE *fin;

   fin=fopen("euclid.in","r");
   fscanf(fin,"%ld",&a);
   fscanf(fin,"%ld",&b);
   fclose(fin);

   return 0;
   }

 int afisare()
  {FILE *fin;

   fin=fopen("euclid.out","w");
   fprintf(fin,"%ld",&x);
   fclose(fin);

   return 0;
   }


 int main()
  {

   citire();

   if (a<b) {x=a;a=b;b=x;}
   while (b!=0)
    {x=b;
     b=a%b;
     a=x;
     }
   x=a;

   afisare();

   return 0;
   }

