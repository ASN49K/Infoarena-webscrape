#include <stdio.h>
#include <stdlib.h>
FILE *f,*g;
int main()
{
  f=fopen("cmmdc.in","r");
  g=fopen("cmmdc.out","w");
  int a,b,n,i;
  fscanf(f,"%d",&n);
  for(i=0;i<n;i++)
 {fscanf(f,"%d",&a);
 fscanf(f,"%d",&b);
 if(a*b==0)
 fprintf(g,"%d",a+b);
 else
 if(a==1 || b==1)
  fprintf(g,"%d",1);
  else
  while(a!=b)
  {
     if(a>b)
     a=a-b;
     else
     b=b-a;

   }

fprintf(g,"%d\n",a);
 }


  return 0;
}
