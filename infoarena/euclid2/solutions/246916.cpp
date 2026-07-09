#include <stdio.h>
long a,b;

int main()
{
 FILE *fin=fopen("euclid2.in","r");
 fscanf (fin,"%ld %ld",&a,&b)  ;
 fclose(fin);
 while (a%b)
  {
   long r=a%b;
   a=b; b=r;
  }
 FILE *fout=fopen("euclid2.out","w");
 fprintf(fout,"%ld\n",b);
 fclose(fout);
return 0;
}
