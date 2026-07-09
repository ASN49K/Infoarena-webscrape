#include <stdio.h>

int cmmdc(int c, int g )
{
  int t;
   while (g!=0)
   {   t=g;
       g=c%g;
       c=t;

   }
 return c;
}
int main()
{
int a,b,c;

FILE *fp;
fp=fopen("euclid2.in","r");
fscanf(fp,"%d",&a);
fscanf(fp,"%d",&b);
c=cmmdc(b,a);
FILE *fw;
fw=fopen("euclid2.out","w");
fprintf(fw,"%d",c);
fclose(fp);
fclose(fw);
}
