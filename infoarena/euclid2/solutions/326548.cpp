#include<iostream>
#include<stdio.h>
 long a,b; 
int div( long a, long b)
{
 if(b==0) return a;
else
return div(b,a%b);
}
  int main()
{
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
  long nrt,i,x,y,n;
 scanf("%ld\n",&nrt);
   for(i=1;i<=nrt;i++)
{
 scanf("%ld %ld\n",&x,&y);
   n=div(x,y);
 printf("%ld\n",n);
}
  return 0;
}

 