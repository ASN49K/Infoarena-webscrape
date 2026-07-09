#include <stdio.h>
#include <stdlib.h>
FILE *f,*g;
int main()
{
  f=fopen("cmmdc.in","r");
  g=fopen("cmmdc.out","w");
  int a,b;
 fscanf(f,"%d%d",&a,&b);
 if(a*b==0)
 fprintf(g,"%d",a+b);
 if(a==1 || b==1)
  fprintf(g,"%d",1);
  while(a!=b &&a*b!=0 &&a!=1 && b!=1)
  {
     if(a>b)
     a=a-b;
     else
     b=b-a;
   }
if(a==b)
fprintf(g,"%d",a);

  return 0;
}
