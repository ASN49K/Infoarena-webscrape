#include <iostream>
#include <stdio.h>

int euclid2(long a,long b);

int main()
{
 FILE * fpin=fopen("euclid2.in","r");
 FILE * fpout=fopen("euclid2.out","w");
 
 int nrPairs;
 fscanf(fpin,"%d",&nrPairs);
 
 for (int i=0;i<nrPairs;i++)
 {
  long a,b;
  fscanf(fpin,"%ld",&a);
  fscanf(fpin,"%ld",&b);
  fprintf(fpout,"%d\n",euclid2(a,b));
 }
 
 fclose(fpin);fclose(fpout);
 return 0;
}

int euclid2(long a,long b)
{
 while (a!=0 && b!=0) 
  if (a>b) a=a%b; else b=b%a; 
 
 if (a!=0) return a; return b;
}
