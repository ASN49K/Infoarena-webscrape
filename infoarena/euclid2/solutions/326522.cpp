#include<stdio.h>
#include<iostream.h>
FILE *f,*g;
int main()
{
long int t,a,b,r,i;
f=fopen("euclid.in","r");
g=fopen("euclid.out","w");
fscanf(f,"%ld\n",&t);
for(i=0;i<t;i++)
{
 fscanf(f,"%ld %ld",&a,&b);
 while(b!=a)
 {
  if(a>b) a=a-b;
    else b=b-a; 
 //r=a%b;
   //a=b;
  // b=r;
 }
 fprintf(g,"%ld\n",a);
}
return 0;
}

