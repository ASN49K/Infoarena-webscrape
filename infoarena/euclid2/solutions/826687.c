#include <stdio.h>

int a , b , T , i;
FILE *f,*g;

int cmmdc (int a , int b)
{
  if(!b)
    return a;
  return cmmdc(b,a%b);
 }

int main()
{
f=fopen("euclid2.in" ,"r");
g=fopen("euclid2.out" ,"w") ;

fscanf(f,"%d",&T);
for(i=1;i<=T;i++)
 {
  fscanf(f,"%d%d",&a,&b);
  fprintf(g,"%d\n",cmmdc(a,b));
 }
return 0;
}