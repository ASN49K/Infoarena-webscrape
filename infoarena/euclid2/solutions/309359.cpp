#include <stdio.h>
#include <string.h>

int main()
{
 FILE *f,*g;
 int a,b,c,i=0,n;
 f=fopen("euclid2.in","r");
 g=fopen("euclid2.out","w");
 fscanf(f,"%d",&n);
 do
 {
  ++i;
  fscanf(f,"%d%d",&a,&b);
  if (a<b) c=a;
  else c=b;
  while ((a%c!=0)||(b%c!=0))
   {
    --c;
   }
  fprintf(g,"%d%s",c,"\n");
 }
 while (i<n);
 fclose(f);
 fclose(g);
 return 0;
}