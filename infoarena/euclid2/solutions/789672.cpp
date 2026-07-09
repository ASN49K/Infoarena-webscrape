#include<fstream>
#include<stdio.h>
 using namespace std;
 int main()
 {
     int a,b,t,r,n,i;
     FILE * f,* g;
     f=fopen("euclid2.in","r");
     g=fopen("euclid2.out","w");
     
     fscanf(f,"%d",&n);
     for(i=1;i<=t;i++)
     {   fscanf(f,"%d","%d",&a,&b);
     while(b)
     {r=a%b;
     a=b;
     b=r;}
     fprintf(g,"%d\n",a);}
     
     return 0;}
     
