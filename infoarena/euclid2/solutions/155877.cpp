#include<iostream>
#include<stdio.h>
FILE *f,*g;
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
  while(y)
  { r=x%y;
    x=y;
    y=r;
  }
  fprintf(g,"%ld\n",x);
 }
return 0;
}