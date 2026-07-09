#include <stdio.h>
//using namespace std;
long a,b;

int main()
{
 FILE *fin=fopen("euclid2.in","r");
 FILE *fout=fopen("euclid2.out","w");
 long t;
 fscanf(fin,"%ld",&t);
 for (long i=1;i<=t;i++)
  {
   fscanf (fin,"%ld %ld",&a,&b)  ;
   while (a%b)
    {
     long r=a%b;
     a=b; b=r;
    }
   fprintf(fout,"%ld\n",b);
  }
 fclose(fin);
 fclose(fout);
return 0;
}
