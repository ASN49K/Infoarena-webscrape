#include <stdio.h>
int a , b , n , i;
FILE f,g;
f=fopen("euclid2.in" ,"r");
g=fopen("euclid2.out" ,"w") ;

int cmmdc (int a , int b)
{
  if(!b)
    return a;
  return cmmdc(b,a%b);
 }

int main()
{
fscanf(f,"%d",&n);
for(i=1,i<=n,i++)
 {
  fscanf(f,"%d",&a);
  fscanf(f,"%d",&b);
  fprintf(g,"%d\n",cmmdc(a,b));
 }
return 0;
}