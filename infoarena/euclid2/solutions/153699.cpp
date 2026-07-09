#include <stdio.h>

 long int a,b,x,i,t;


 int main()
  {FILE *fin,*fout;

   fin=fopen("euclid2.in","r");
   fout=fopen("euclid2.out","w");

   fscanf(fin,"%ld",&t);
   for (i=1;i<=t;i++)
     {fscanf(fin,"%ld",&a);
      fscanf(fin,"%ld",&b);
      if (a<b) {x=a;a=b;b=x;}
      while (b)
        {x=b;
         b=a%b;
         a=x;
         }
      x=a;
      fprintf(fout,"%ld\n",x);
      }

   fclose(fin);
   fclose(fout);

   return 0;
   }

