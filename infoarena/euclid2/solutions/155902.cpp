#include<iostream.h>
#include<stdio.h>
FILE *f,*g;
int cmmdc(int a,int b)
{
 if(!b)
  return a;
 else
  return cmmdc(b,a%b);
}
int main ()
{
 long t, a,b,r,x,y,i;
 f=fopen("euclid2.in","r");
 g=fopen("euclid2.out","w");
 fscanf(f,"%ld\n",&t);
 for(i=1;i<=t;i++)
 {
  fscanf(f,"%ld %ld\n",&a,&b);
  if(a>b) {x=a;y=b;}
  else {x=b;y=a;}
  r=cmmdc(x,y);
  fprintf(g,"%ld\n",r);
 }
return 0;
}
