#include <stdio.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
long euclid(long a,long b)
 {
 if(b==0)
  return a;
 return euclid(b,a%b);               
 }
int main()
 {
 long a,b,n,i,x;
 fscanf(f,"%d",&n);
 for(i=1;i<=n;i++)
  {
  fscanf(f,"%d %d",&a,&b);
  x=euclid(a,b);
  fprintf(g,"%d\n",x);         
  } 
 return 0;
 }
